/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_cmds.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 13:27:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/10/29 14:00:31 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>

static void	free_cmd(t_cmd cmd)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cmd.argc)
	{
		string_free(&cmd.argv[i]);
		i++;
	}
	free(cmd.argv);
	j = 0;
	while (j < cmd.redir_count)
	{
		string_free(&cmd.redir_files[j].redir_filename);
		j++;
	}
	free(cmd.redir_files);
}

void		free_cmds(t_cmd *cmds, size_t cmd_count)
{
	size_t	i;

	i = 0;
	while (i < cmd_count)
	{
		free_cmd(cmds[i]);
		i++;
	}
}
