/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_proc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 16:37:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/16 12:52:15 by aaugusti      ########   odam.nl         */
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

static void	run_child_builtin(t_mshell *mshell, t_builtin_func builtin,
		t_cmd cmd)
{
	// TODO Some builtins should not run in a child
	exit(builtin(mshell, cmd));
}

static void	run_child_file(t_mshell *mshell, char *path, t_cmd cmd)
{
	char **argvp;
	char **envp;

	argvp = string_to_array(cmd.argc, cmd.argv);
	if (argvp == NULL)
		error(E_ALLOC "'run_child'", mshell);
	envp = env_to_envp(mshell);
	execve(path, argvp, envp);
}

static void	start_proc_parent(t_mshell *mshell, pid_t pid, char *path)
{
	int	exit_status;

	if (waitpid(pid, &exit_status, 0) == -1)
		error(E_WAITPID "'start_proc_parent'", mshell);
	free(path);
	mshell->last_exit = exit_status;
}

static void	start_proc_child(t_mshell *mshell, t_cmd cmd,
		t_builtin_func builtin, char *path)
{
	handle_redirs(mshell, cmd);
	if (builtin != NULL)
		run_child_builtin(mshell, builtin, cmd);
	else if (path != NULL)
		run_child_file(mshell, path, cmd);
	else
	{
		// TODO Handle error
		exit(1);
	}
}

void		start_proc(t_mshell *mshell, t_cmd cmd)
{
	char			*path;
	pid_t			pid;
	t_builtin_func	builtin;

	builtin = find_builtin(cmd.argv[0]);
	path = path_find_file(mshell, cmd.argv[0].str, true);
	pid = fork();
	if (pid == -1)
		error(E_FORK "'start_proc'", mshell);
	if (pid == 0)
		start_proc_child(mshell, cmd, builtin, path);
	else
		start_proc_parent(mshell, pid, path);
}
