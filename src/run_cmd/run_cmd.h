/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/16 12:56:01 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/16 12:56:53 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CMD_H
# define RUN_CMD_H

# include <minishell.h>

typedef struct	s_redir_spec {
	int	target;
	int	oflags;
	int	omode;
}				t_redir_spec;

void			free_cmds(t_cmd *cmds, size_t cmd_count);
void			handle_redir_files(t_mshell *mshell, t_redir_file *redir_files,
		size_t redir_count, t_cmd_directions *directions);
t_builtin_func	find_builtin(t_string name);
void			start_proc(t_mshell *mshell, t_cmd cmd);
void			handle_redirs(t_mshell *mshell, t_cmd cmd);

#endif
