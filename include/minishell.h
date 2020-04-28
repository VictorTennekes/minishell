/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:15:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/28 09:33:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <liblist.h>
# include <libstring.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define SHELL "minishell"
# define E_ALLOC "Allocation failed in "
# define E_READ "Read failed in "
# define CWD_INIT_CAP (100)
# define MS_PERROR_INIT_CAP (100)

typedef uint32_t	t_errno;

enum				e_errno {
	ENO_INVID = 1,
	ENO_INVCMD = 2,
	ENO_TMA = 3,
	ENO_HOME = 4,
	ENO_OLDPWD = 5,
	ENO_USET = 6,
};

typedef struct	s_mshell {
	t_list		*env;
	t_list		*path;
	t_errno		ms_errno;
	t_string	ms_err_procname;
	bool		ms_stderrno;
}				t_mshell;

/*
**	Builtin functions.
*/

bool		builtin_cd(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_echo(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_env(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_exit(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_export(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_pwd(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_unset(t_mshell *mshell, uint32_t argc, t_string argv[]);

/*
**	A struct for storing all builtin commands and their corresponding
**	functions.
*/

typedef struct	s_builtin {
	char		*cmd;
	bool		(*func)(t_mshell * mshell, uint32_t argc, t_string argv[]);
}				t_builtin;

bool		ms_set_error(t_mshell *mshell, t_errno ms_errno, char *procname);
bool		ms_set_error_from_no(t_mshell *mshell, char *procname, char *err);
t_string	*parser(t_mshell *mshell, t_string *cmd, uint32_t *argc);
t_string	get_cmd(t_mshell *mshell);
void		error(char *msg, t_mshell *mshell);
void		init(t_mshell *mshell);
void		ms_free(t_mshell *mshell);
void		ms_perror(t_mshell *mshell);
void		ms_set_procname(t_mshell *mshell, char *procname);
void		ms_set_procname_err(t_mshell *mshell, char *procname, char *err);
void		prompt(t_mshell *mshell);
void		run_cmd(t_mshell *mshell, t_string *cmd);

/*
**	Utils
*/

char		*get_cwd(t_mshell *mshell);
int			file_wapper(char *filename, int (*func)(int fd));
int			file_wapper_arg(char *filename, int (*func)(int fd, void *arg),
				void *arg);
void		*zalloc(size_t size);
void		print_env(t_mshell *mshell, char *prefix);

#endif
