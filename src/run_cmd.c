/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:31:42 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/18 16:26:19 by aaugusti      ########   odam.nl         */
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
#include <libftprintf.h>

static bool	tmp_printpath(t_mshell *mshell, t_cmd cmd)
{
	t_list	*cur;

	(void)cmd;
	cur = mshell->path;
	while (cur)
	{
		ft_printf("%s\n", cur->content);
		cur = cur->next;
	}
	return (0);
}

t_builtin	g_builtins[] = {
	{ "cd", 	builtin_cd },
	{ "echo", 	builtin_echo },
	{ "env", 	builtin_env },
	{ "exit", 	builtin_exit },
	{ "export", builtin_export },
	{ "pwd", 	builtin_pwd },
	{ "unset", 	builtin_unset },
	{ "printpath", tmp_printpath },
	{ NULL , 	NULL },
};

static void	free_cmd(t_cmd cmd)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	j = 0;
	while (i < cmd.argc)
	{
		string_free(&cmd.argv[i]);
		i++;
	}
	while(j < cmd.redir_count)
	{
		string_free(&cmd.redir_files[j].redir_filename);
		j++;
	}
	free(cmd.redir_files);
	free(cmd.argv);
}

static int start_proc(t_mshell *mshell, char *filename, t_cmd cmd)
{
	char	**argvp;
	char	**envp;
	int		child_pid;
	int		exit_status;
	int		ret;

	child_pid = fork();
	ret = 0;
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
		ret = execve(filename, argvp, envp);
		free(filename);
		error("Unknown command" , mshell);
	}
	return (ret);
}

static bool	run_cmd_exec(t_mshell *mshell, t_cmd cmd)
{
	char	*filename;

	filename = path_find_file(mshell, cmd.argv[0].str, true);
	if (filename)
	{
		start_proc(mshell, filename, cmd);
		free(filename);
	}
	else
	{
		ms_set_procname(mshell, cmd.argv[0].str);
		filename = mshell->ms_err_procname.str;
		if (start_proc(mshell, filename, cmd) == -1)
		{
			mshell->ms_errno = ENO_INVCMD;
			ms_perror(mshell);
		}
	}
	return (filename ? true : false);
}

static void	run_cmd_single(t_mshell *mshell, t_cmd cmd)
{
	uint32_t	i;

	i = 0;
	if (cmd.argc == 0)
	{
		free_cmd(cmd);
		return ;
	}
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
	char		*last_exit;

	if (ft_strlen(cmd) == 0)
	{
		free(cmd);
		last_exit = ft_itoa(mshell->last_exit);
		env_set(mshell, "?", last_exit, false);
		free(last_exit);
		return ;
	}
	i = 0;
	cmds = parser(mshell, cmd, &cmd_count);
	if (cmds == NULL)
		return ;
	free(cmd);
	while (i < cmd_count)
	{
		replace_env(mshell, cmds[i]);
		run_cmd_single(mshell, cmds[i]);
		i++;
	}
	free(cmds);
	last_exit = ft_itoa(mshell->last_exit);
	env_set(mshell, "?", last_exit, false);
	free(last_exit);
}
