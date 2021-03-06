/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:15:57 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:55:13 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <cmd.h>
# include <liblist.h>
# include <libstring.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define SHELL "minishell"
# define E_ALLOC "malloc failed in "
# define E_READ "read failed in "
# define E_GNL "get_next_line failed in "
# define E_FORK "fork failed in "
# define E_PIPE "pipe failed in "
# define E_DUP2 "dup2 failed in "
# define E_CLOSE "close failed in "
# define E_WAITPID "waitpid failed in "
# define CWD_INIT_CAP 100
# define MS_PERROR_INIT_CAP 100

typedef uint32_t	t_errno;

enum				e_errno {
	ENO_INVID = 1,
	ENO_INVCMD = 2,
	ENO_TMA = 3,
	ENO_HOME = 4,
	ENO_OLDPWD = 5,
	ENO_USET = 6,
	ENO_UNEXTOK = 7,
	ENO_UNEXEOF = 8,
	ENO_NOFILE = 9,
	ENO_DEFAULT = 10,
};

typedef struct		s_mshell {
	t_list			*env;
	t_list			*path;
	t_errno			ms_errno;
	t_string		ms_err_procname;
	bool			ms_stderrno;
	int				last_exit;
	bool			signal;
}					t_mshell;

/*
**	Builtin functions.
*/

bool				builtin_cd(t_mshell *mshell, t_cmd cmd);
bool				builtin_echo(t_mshell *mshell, t_cmd cmd);
bool				builtin_env(t_mshell *mshell, t_cmd cmd);
bool				builtin_exit(t_mshell *mshell, t_cmd cmd);
bool				builtin_export(t_mshell *mshell, t_cmd cmd);
bool				builtin_pwd(t_mshell *mshell, t_cmd cmd);
bool				builtin_unset(t_mshell *mshell, t_cmd cmd);

/*
**	A struct for storing all builtin commands and their corresponding
**	functions.
*/

typedef	bool		(*t_builtin_func)(t_mshell *, t_cmd);

typedef struct		s_builtin {
	char			*cmd;
	t_builtin_func	func;
}					t_builtin;

bool				ms_set_error(t_mshell *mshell, t_errno ms_errno,
					char *procname);
bool				ms_set_error_from_no(t_mshell *mshell, char *procname,
					char *err);
t_cmd				*parser(t_mshell *mshell, char *cmd, size_t *cmd_count);
char				*get_cmd(t_mshell *mshell);
void				error(char *msg, t_mshell *mshell);
void				init(t_mshell *mshell);
void				ms_free(t_mshell *mshell);
void				ms_perror(t_mshell *mshell);
void				ms_set_procname(t_mshell *mshell, char *procname);
void				ms_set_procname_err(t_mshell *mshell, char *procname,
					char *err);
void				prompt(t_mshell *mshell);
void				run_cmd(t_mshell *mshell, char *cmd);

/*
**	Utils
*/

char				*get_cwd(t_mshell *mshell);
void				*zalloc(size_t size);
void				print_env(t_mshell *mshell, char *prefix);
void				init_signal(t_mshell *mshell);
char				**free_str_arr(char **str);

#endif
