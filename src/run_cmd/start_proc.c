/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_proc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 16:37:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 16:04:31 by aaugusti      ########   odam.nl         */
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

static void	free_and_exit(t_mshell *mshell, char *path, char *procname)
{
	bool	is_relative;

	is_relative = ft_strchr(procname, '/') == NULL;
	free(path);
	if (is_relative)
		ms_set_error(mshell, ENO_INVCMD, procname);
	else
	{
		mshell->ms_stderrno = true;
		ms_set_procname(mshell, procname);
	}
	free(procname);
	ms_perror(mshell);
	ms_free(mshell);
	exit(1);
}

static void	run_child_file(t_mshell *mshell, char *path, t_cmd cmd)
{
	char	**argvp;
	char	**envp;
	char	*procname;

	argvp = string_to_array(cmd.argc, cmd.argv);
	if (argvp == NULL)
		error(E_ALLOC "'run_child'", mshell);
	envp = env_to_envp(mshell);
	procname = ft_strdup(cmd.argv[0].str);
	if (procname == NULL)
		error(E_ALLOC "'run_child_file'", mshell);
	if (execve(path == NULL ? cmd.argv[0].str : path, argvp, envp) == -1)
	{
		free_str_arr(envp);
		free_str_arr(argvp);
		free_and_exit(mshell, path, procname);
	}
}

static void	start_proc_parent(t_mshell *mshell, pid_t pid, char *path)
{
	int	exit_status;

	if (waitpid(pid, &exit_status, 0) == -1)
		error(E_WAITPID "'start_proc_parent'", mshell);
	free(path);
	if (WIFEXITED(exit_status))
		mshell->last_exit = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		mshell->last_exit = WTERMSIG(exit_status) - 128;
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
