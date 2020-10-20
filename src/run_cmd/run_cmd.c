/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 13:27:35 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/10/20 13:27:35 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"
#include "run_cmd.h"
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>
#include <env.h>

static void	run_cmd_single(t_mshell *mshell, t_cmd cmd)
{
	char *last_exit;
	
	start_proc(mshell, cmd);
	last_exit = ft_itoa(mshell->last_exit);
	env_set(mshell, "?", last_exit, false);
	free(last_exit);
}

static void dupclose_fd(int fd, int sec_fd)
{
	if (fd != sec_fd)
	{
		dup2(fd, sec_fd);
		close(fd);
	}
}

static void	if_pipe(t_mshell *mshell, int *pfds, int prev_pipe, t_cmd cmd)
{
	int pipe_ret;
	int pid;

	pipe_ret = pipe(pfds);
	if (pipe_ret == -1)
		error(E_PIPE "'run_cmds'", mshell);
	pid = fork();
	if (pid == -1)
		error(E_FORK "'run_cmds'", mshell);
	if (pid == 0)
	{
		dupclose_fd(prev_pipe, STDIN_FILENO);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
		run_cmd_single(mshell, cmd);
		exit(1);
	}
}

static void	run_cmds(t_mshell *mshell, t_cmd *cmds, size_t cmd_count)
{
	size_t	i;
	int		pfds[2];
	int		prev_pipe;
	int		std_in;

	i = 0;
	prev_pipe = STDIN_FILENO;
	while (i < cmd_count - 1)
	{
		replace_env(mshell, cmds[i]);
		if (cmds[i].pipe == true)
			if_pipe(mshell, pfds, prev_pipe, cmds[i]);
		if (prev_pipe != STDIN_FILENO)
			close(prev_pipe);
		if (cmds[i].pipe == true)
		{
			close(pfds[1]);
			prev_pipe = pfds[0];
		}
		i++;
	}
	std_in = dup(STDIN_FILENO);
	dupclose_fd(prev_pipe, STDIN_FILENO);
	replace_env(mshell, cmds[i]);
	run_cmd_single(mshell, cmds[i]);
	dup2(std_in, STDIN_FILENO);
}

void		run_cmd(t_mshell *mshell, char *cmd)
{
	size_t	cmd_count;
	t_cmd	*cmds;

	cmds = parser(mshell, cmd, &cmd_count);
	free(cmd);
	if (cmds == NULL)
	{
		ms_perror(mshell);
		return ;
	}
	run_cmds(mshell, cmds, cmd_count);
	free_cmds(cmds, cmd_count);
}
