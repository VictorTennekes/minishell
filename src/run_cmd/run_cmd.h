/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_cmd.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/16 12:56:01 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 15:09:02 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_CMD_H
# define RUN_CMD_H

# include <minishell.h>

typedef struct	s_redir_spec {
	int			target;
	int			oflags;
	int			omode;
}				t_redir_spec;

typedef struct	s_pipe_info {
	int			pfds[2];
	int			prev_pipe;
	t_cmd		cmd;
}				t_pipe_info;

void			free_cmds(t_cmd *cmds, size_t cmd_count);
void			handle_redir_files(t_mshell *mshell, t_redir_file *redir_files,
		size_t redir_count, t_cmd_directions *directions);
t_builtin_func	find_builtin(t_string name);
void			start_proc(t_mshell *mshell, t_cmd cmd, char *path);
void			handle_redirs(t_mshell *mshell, t_cmd cmd);
bool			handle_builtin(t_mshell *mshell, t_cmd cmd,
		t_builtin_func builtin, int *exit_status);
void			if_pipe(t_mshell *mshell, t_pipe_info *pipe_data,
		t_cmd *cmds, size_t cmd_count);
void			dupclose_fd(int fd, int sec_fd);

#endif
