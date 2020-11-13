/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_redirs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/16 12:47:45 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/28 14:37:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "run_cmd.h"
#include <fcntl.h>
#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>

t_redir_spec	g_redir_specs[] = {
	[WRITE] = {
		.target = STDOUT_FILENO,
		.oflags = O_WRONLY | O_CREAT,
		.omode = 0664
	},
	[APPEND] = {
		.target = STDOUT_FILENO,
		.oflags = O_WRONLY | O_APPEND,
		.omode = 0664
	},
	[INPUT] = {
		.target = STDIN_FILENO,
		.oflags = O_RDONLY,
		.omode = 0
	},
};

void	open_files(t_mshell *mshell, t_cmd cmd, t_cmd_directions *directions)
{
	t_redir_file	cur_redir;
	t_redir_spec	cur_spec;
	size_t			i;

	i = 0;
	ft_bzero(directions, sizeof(t_cmd_directions));
	while (i < cmd.redir_count)
	{
		cur_redir = cmd.redir_files[i];
		cur_spec = g_redir_specs[cur_redir.redir_type];
		if (directions->has_redirect[cur_redir.redir_type])
			if (close(directions->redirect_fd[cur_redir.redir_type]) == -1)
				error(E_CLOSE "'handle_redirs'", mshell);
		directions->has_redirect[cur_redir.redir_type] = true;
		directions->redirect_fd[cur_redir.redir_type] =
			open(cur_redir.redir_filename.str, cur_spec.oflags, cur_spec.omode);
		if (directions->redirect_fd[cur_redir.redir_type] == -1)
		{
			ms_set_error(mshell, ENO_NOFILE, cur_redir.redir_filename.str);
			ms_perror(mshell);
			mshell->last_exit = 1;
			exit(mshell->last_exit);
		}
		i++;
	}
}

void	replace_stdin_out(t_mshell *mshell, t_cmd_directions directions)
{
	size_t	i;
	int		target_fd;

	i = 0;
	while (i < 3)
	{
		if (directions.has_redirect[i])
		{
			target_fd = g_redir_specs[i].target;
			if (close(target_fd) == -1)
				error(E_CLOSE "'handle_redirs'", mshell);
			if (dup2(directions.redirect_fd[i], target_fd) == -1)
				error(E_DUP2 "'handle_redirs'", mshell);
		}
		i++;
	}
}

void	handle_redirs(t_mshell *mshell, t_cmd cmd)
{
	t_cmd_directions	directions;

	open_files(mshell, cmd, &directions);
	replace_stdin_out(mshell, directions);
}
