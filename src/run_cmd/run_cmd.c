#include "cmd.h"
#include "libft.h"
#include "run_cmd.h"
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>

static void	run_cmd_single(t_mshell *mshell, t_cmd cmd)
{
	start_proc(mshell, cmd);
}

static void dupclose_fd(int fd, int sec_fd)
{
	if (fd != sec_fd)
	{
		dup2(fd, sec_fd);
		close(fd);
	}
}

static void	run_cmds(t_mshell *mshell, t_cmd *cmds, size_t cmd_count)
{
	size_t	i;
	int		pfds[2];
	int		prev_pipe;
	int		std_in;
	int		pid;

	i = 0;
	prev_pipe = STDIN_FILENO;
	while (i < cmd_count - 1)
	{
		if (cmds[i].pipe == true)
		{
			pipe(pfds);
			pid = fork();
			if (pid == -1)
				error(E_FORK "'run_cmds'", mshell);
			if (pid == 0)
			{
				dupclose_fd(prev_pipe, STDIN_FILENO);
				dup2(pfds[1], STDOUT_FILENO);
				close(pfds[1]);
				run_cmd_single(mshell, cmds[i]);
				exit(1);
			}
		}
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
