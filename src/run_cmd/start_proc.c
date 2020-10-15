#include <minishell.h>
#include "cmd.h"
#include "env.h"
#include "run_cmd.h"
#include <path.h>
#include <unistd.h>

int			g_redir_fds[] = {
	[WRITE] = STDOUT_FILENO,
	[APPEND] = STDOUT_FILENO,
	[INPUT] = STDIN_FILENO,
};

//static void	handle_directions(t_mshell *mshell, t_cmd_directions *directions)
//{
	//(void)mshell;
	//(void)directions;
//}

static void	run_child_builtin(t_mshell *mshell, t_builtin_func builtin, t_cmd cmd, t_cmd_directions *directions)
{
	(void)mshell;
	(void)builtin;
	(void)cmd;
	(void)directions;
}

static void	run_child_file(t_mshell *mshell, char *filename, t_cmd cmd, t_cmd_directions *directions)
{
	char **argvp;
	char **envp;

	(void)directions;
	argvp = string_to_array(cmd.argc, cmd.argv);
	if (argvp == NULL)
		error(E_ALLOC "'run_child'", mshell);
	envp = env_to_envp(mshell);
	execve(filename, argvp, envp);
}

void		start_proc(t_mshell *mshell, t_cmd cmd, t_cmd_directions *directions)
{
	t_builtin_func	builtin;
	char			*filename;
	int				pid;

	builtin = find_builtin(cmd.argv[0]);
	filename = path_find_file(mshell, cmd.argv[0].str, true);
	pid = fork();
	if (pid == -1)
		error(E_FORK "'start_proc'", mshell);
	if (pid == 0)
	{
		// Child
		if (builtin != NULL)
			run_child_builtin(mshell, builtin, cmd, directions);
		else if (filename != NULL)
			run_child_file(mshell, filename, cmd, directions);
		else
		{
			// HANDLE ERROR
		}
	}
	else
	{
		// Parent
	}
}
