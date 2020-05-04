/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:31:42 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/29 19:47:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmd.h>
#include <env.h>
#include <libft.h>
#include <minishell.h>
#include <path.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

t_builtin	g_builtins[] = {
	{ "cd", 	builtin_cd },
	{ "echo", 	builtin_echo },
	{ "env", 	builtin_env },
	{ "exit", 	builtin_exit },
	{ "export", builtin_export },
	{ "pwd", 	builtin_pwd },
	{ "unset", 	builtin_unset },
	{ NULL , 	NULL },
};

static void	free_cmd(t_cmd cmd)
{
	uint32_t	i;

	i = 0;
	while (i < cmd.argc)
	{
		string_free(&cmd.argv[i]);
		i++;
	}
	free(cmd.argv);
}

static void start_proc(t_mshell *mshell, char *filename, t_cmd cmd)
{
	char	**argvp;
	char	**envp;
	int		child_pid;
	int		exit_status;

	child_pid = fork();

	if (child_pid)
	{
		if (waitpid(child_pid, &exit_status, 0) == -1)
			error("waitpid failed in 'start_proc'", mshell);
		mshell->last_exit = WEXITSTATUS(exit_status);
	}
	else
	{
		argvp = string_to_array(cmd.argc, cmd.argv);
		if (!argvp)
			error(E_ALLOC "'start_proc'", mshell);
		envp = env_to_envp(mshell);
		execve(filename, argvp, envp);
	}
}

static bool	run_cmd_exec(t_mshell *mshell, t_cmd cmd)
{
	char	*filename;

	filename = path_find_file(mshell, cmd.argv[0].str, true);
	if (filename)
		start_proc(mshell, filename, cmd);
	else
	{
		ms_set_procname(mshell, cmd.argv[0].str);
		mshell->ms_errno = ENO_INVCMD;
		ms_perror(mshell);
	}
	free(filename);
	return (filename ? true : false);
}

static void	run_cmd_single(t_mshell *mshell, t_cmd cmd, t_cmd *cmds)
{
	uint32_t	i;

	if (cmd.argc == 0)
	{
		free_cmd(cmd);
		free(cmds);
		builtin_exit(mshell, cmd);
	}
	i = 0;
	while (g_builtins[i].cmd)
	{
		if (!ft_strcmp(cmd.argv[0].str, g_builtins[i].cmd))
		{
			if (g_builtins[i].func(mshell, cmd))
				ms_perror(mshell);
			free_cmd(cmd);
			return ;
		}
		i++;
	}
	//TODO handle a 'true' return
	run_cmd_exec(mshell, cmd);
	free_cmd(cmd);
}

void		run_cmd(t_mshell *mshell, char *cmd)
{
	size_t		cmd_count;
	size_t		i;
	t_cmd		*cmds;

	i = 0;
	cmds = parser(mshell, cmd, &cmd_count);
	free(cmd);
	while (i < cmd_count)
	{
		run_cmd_single(mshell, cmds[i], cmds);
		i++;
	}
	free(cmds);
}
