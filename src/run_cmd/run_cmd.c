#include "cmd.h"
#include "libft.h"
#include "run_cmd.h"
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>

static void	close_directions(t_cmd_directions *directions)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (directions->has_redirect[i])
			close(directions->redirect_fd[i]);
		i++;
	}
}

static void	run_cmd_single(t_mshell *mshell, t_cmd cmd)
{
	t_cmd_directions	directions;

	ft_bzero(&directions, sizeof(t_cmd_directions));
	handle_redir_files(mshell, cmd.redir_files, cmd.redir_count, &directions);
	close_directions(&directions);
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
