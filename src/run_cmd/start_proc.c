/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_proc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 16:37:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/22 13:36:16 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "run_cmd.h"
#include <fcntl.h>
#include <path.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	run_child_file(t_mshell *mshell, char *path, t_cmd cmd)
{
	char **argvp;
	char **envp;

	argvp = string_to_array(cmd.argc, cmd.argv);
	if (argvp == NULL)
		error(E_ALLOC "'run_child'", mshell);
	envp = env_to_envp(mshell);
	if (execve(path == NULL ? cmd.argv[0].str : path, argvp, envp) == -1)
		error("Unknown command", mshell);
}

static void	start_proc_parent(t_mshell *mshell, pid_t pid, char *path)
{
	int	exit_status;

	if (waitpid(pid, &exit_status, 0) == -1)
		error(E_WAITPID "'start_proc_parent'", mshell);
	free(path);
	mshell->last_exit = exit_status;
}

static void	start_proc_child(t_mshell *mshell, t_cmd cmd, char *path)
{
	handle_redirs(mshell, cmd);
	run_child_file(mshell, path, cmd);
}

void		start_proc(t_mshell *mshell, t_cmd cmd, char *path)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		error(E_FORK "'start_proc'", mshell);
	if (pid == 0)
		start_proc_child(mshell, cmd, path);
	else
		start_proc_parent(mshell, pid, path);
}
