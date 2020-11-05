/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:57:09 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/10/29 15:10:56 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "run_cmd.h"
#include <minishell.h>
#include <unistd.h>
#include <stdlib.h>

static void	run_child_builtin(t_mshell *mshell, t_builtin_func builtin,
		t_cmd cmd)
{
	int	exit_status;

	handle_redirs(mshell, cmd);
	exit_status = builtin(mshell, cmd);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		exit_status = WTERMSIG(exit_status) - 128;
	if (exit_status)
		ms_perror(mshell);
	ms_free(mshell);
	exit(exit_status);
}

bool		handle_builtin(t_mshell *mshell, t_cmd cmd,
		t_builtin_func builtin, int *exit_status)
{
	int pid;

	if (cmd.redir_count > 0)
	{
		pid = fork();
		if (pid == 0)
			run_child_builtin(mshell, builtin, cmd);
	}
	else
	{
		*exit_status = builtin(mshell, cmd);
		if (*exit_status)
			ms_perror(mshell);
		if (cmd.pipe)
			return (true);
	}
	return (false);
}

void		dupclose_fd(int fd, int sec_fd)
{
	if (fd != sec_fd)
	{
		dup2(fd, sec_fd);
		close(fd);
	}
}
