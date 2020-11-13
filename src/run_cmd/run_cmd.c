/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 13:27:35 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/10/29 13:59:53 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"
#include "run_cmd.h"
#include <env.h>
#include <minishell.h>
#include <path.h>
#include <stdlib.h>
#include <unistd.h>

static bool check_cmds(t_mshell *mshell, t_cmd *cmds, size_t cmd_count)
{
	size_t i;

	i = 0;
	while (i < cmd_count)
	{
		if (cmds[i].argc == 0)
		{
			ms_set_error(mshell, ENO_UNEXTOK, "");
			ms_perror(mshell);
			return (true);
		}
		i++;
	}
	return (false);
}

static void	run_cmd_single(t_mshell *mshell, t_cmd cmd,
		t_cmd *cmds, size_t cmd_count)
{
	char			*exit_string;
	char			*path;
	int				exit_status;
	t_builtin_func	builtin;

	exit_status = 0;
	path = path_find_file(mshell, cmd.argv[0].str, true);
	builtin = find_builtin(cmd.argv[0]);
	if (builtin)
	{
		free(path);
		if (handle_builtin(mshell, cmd, builtin, &exit_status))
		{
			free_cmds(cmds, cmd_count);
			ms_free(mshell);
			exit(exit_status);
		}
	}
	else
		start_proc(mshell, cmd, path);
	exit_status = (builtin == NULL) ? mshell->last_exit : exit_status;
	mshell->last_exit = exit_status;
	exit_string = ft_itoa(exit_status);
	env_set(mshell, "?", exit_string, false);
	free(exit_string);
}

void		if_pipe(t_mshell *mshell, t_pipe_info *pipe_data,
		t_cmd *cmds, size_t cmd_count)
{
	int pipe_ret;
	int pid;

	pipe_ret = pipe(pipe_data->pfds);
	if (pipe_ret == -1)
		error(E_PIPE "'run_cmds'", mshell);
	pid = fork();
	if (pid == -1)
		error(E_FORK "'run_cmds'", mshell);
	if (pid == 0)
	{
		dupclose_fd(pipe_data->prev_pipe, STDIN_FILENO);
		dup2(pipe_data->pfds[1], STDOUT_FILENO);
		close(pipe_data->pfds[1]);
		run_cmd_single(mshell, pipe_data->cmd, cmds, cmd_count);
		exit(1);
	}
}

static void	run_cmds(t_mshell *mshell, t_cmd *cmds, size_t cmd_count)
{
	size_t		i;
	t_pipe_info	pipe_data;
	int			std_in;

	i = 0;
	pipe_data.prev_pipe = STDIN_FILENO;
	while (i < cmd_count - 1)
	{
		pipe_data.cmd = cmds[i];
		if (cmds[i].pipe == true)
			if_pipe(mshell, &pipe_data, cmds, cmd_count);
		if (pipe_data.prev_pipe != STDIN_FILENO)
			close(pipe_data.prev_pipe);
		if (cmds[i].pipe == true)
		{
			close(pipe_data.pfds[1]);
			pipe_data.prev_pipe = pipe_data.pfds[0];
		}
		else
			run_cmd_single(mshell, cmds[i], cmds, cmd_count);
		i++;
	}
	std_in = dup(STDIN_FILENO);
	dupclose_fd(pipe_data.prev_pipe, STDIN_FILENO);
	run_cmd_single(mshell, cmds[i], cmds, cmd_count);
	dup2(std_in, STDIN_FILENO);
}

void		run_cmd(t_mshell *mshell, char *cmd)
{
	size_t	cmd_count;
	t_cmd	*cmds;

	cmds = parser(mshell, cmd, &cmd_count);
	free(cmd);
	if (cmds == NULL)
		return ;
	if (check_cmds(mshell, cmds, cmd_count))
		return ;
	run_cmds(mshell, cmds, cmd_count);
	free_cmds(cmds, cmd_count);
	free(cmds);
}
