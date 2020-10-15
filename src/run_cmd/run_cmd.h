#ifndef RUN_CMD_H
# define RUN_CMD_H

# include <minishell.h>

void			free_cmds(t_cmd *cmds, size_t cmd_count);
void			handle_redir_files(t_mshell *mshell, t_redir_file *redir_files,
		size_t redir_count, t_cmd_directions *directions);
t_builtin_func	find_builtin(t_string name);

#endif
