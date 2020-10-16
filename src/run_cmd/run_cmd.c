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

static void	run_cmds(t_mshell *mshell, t_cmd *cmds, size_t cmd_count)
{
	size_t	i;

	i = 0;
	while (i < cmd_count)
	{
		run_cmd_single(mshell, cmds[i]);
		i++;
	}
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
