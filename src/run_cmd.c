/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:31:42 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 14:09:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

static void	free_args(uint32_t argc, t_string argv[])
{
	uint32_t	i;

	i = 0;
	while (i < argc)
	{
		string_free(&argv[i]);
		i++;
	}
	free(argv);
}

static void start_proc(t_mshell *mshell, char *filename, uint32_t argc, t_string argv[])
{
	char	**argvp;
	char	**envp;
	int		child_pid;

	child_pid = fork();

	if (child_pid == 0)
	{
		argvp = string_to_array(argc, argv);
		if (!argvp)
			error(E_ALLOC "'start_proc'", mshell);
		envp = env_to_envp(mshell);
		execve(filename, argvp, envp);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}

static bool	run_cmd_exec(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	char	*filename;

	(void)argc;
	filename = path_find_file(mshell, argv[0].str, true);
	if (!filename)
	{
		ms_set_procname(mshell, argv[0].str);
		mshell->ms_errno = ENO_INVCMD;
		ms_perror(mshell);
	}
	else
		start_proc(mshell, filename, argc, argv);
	free(filename);
	return (filename ? true : false);
}

void		run_cmd(t_mshell *mshell, t_string *cmd)
{
	t_string	*argv;
	uint32_t	argc;
	uint32_t	i;

	if (!*cmd->str)
		return ;
	i = 0;
	argv = parser(mshell, cmd, &argc);
	if (!argv)
		error(E_ALLOC "'run_cmd'", mshell);
	while (g_builtins[i].cmd)
	{
		if (!ft_strcmp(argv[0].str, g_builtins[i].cmd))
		{
			if (g_builtins[i].func(mshell, argc, argv))
				ms_perror(mshell);
			free_args(argc, argv);
			return ;
		}
		i++;
	}
	//TODO handle a 'true' return
	run_cmd_exec(mshell, argc, argv);
	free_args(argc, argv);
}
