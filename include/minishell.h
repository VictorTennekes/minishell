/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:15:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/01 20:13:00 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <liblist.h>
# include <libstring.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define E_ALLOC "Allocation failed in "
# define E_READ "Read failed in "
# define CWD_INIT_SIZE (100)

typedef struct	s_mshell {
	t_list	*env;
	t_list	*path;
}				t_mshell;

/*
**	Builtin functions.
*/

bool		builtin_cd(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_echo(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_env(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_exit(t_mshell *mshell, uint32_t argc, t_string argv[]);
bool		builtin_pwd(t_mshell *mshell, uint32_t argc, t_string argv[]);

/*
**	A struct for storing all builtin commands and their corresponding
**	functions.
*/

typedef struct	s_builtin {
	char		*cmd;
	bool		(*func)(t_mshell * mshell, uint32_t argc, t_string argv[]);
}				t_builtin;

t_string	*parser(t_string *cmd, uint32_t *argc);
t_string	get_cmd(void);
void		error(char *msg);
void		init(t_mshell *mshell);
void		prompt(t_mshell *mshell);
void		run_cmd(t_mshell *mshell, t_string *cmd);

/*
**	Utils
*/

char		*get_cwd(void);
int			file_wapper(char *filename, int (*func)(int fd));
void		*zalloc(size_t size);

#endif
