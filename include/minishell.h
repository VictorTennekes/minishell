/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:15:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:19:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libstring.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define E_ALLOC "Allocation failed in "
# define E_READ "Read failed in "

/*
**	Builtin functions.
*/

//void	builtin_exit(char **args);
void		builtin_echo(uint32_t argc, t_string argv[]);

/*
**	A list of all builtin commands and their corresponding functions.
*/

typedef struct	s_cmd {
	char		*cmd;
	int32_t		maxargc;
	void		(*func)(uint32_t argc, t_string argv[]);
}				t_cmd;

t_string	*parser(t_string *cmd, uint32_t *argc);
t_string	get_cmd(void);
void		error(char *msg);
void		prompt(void);
void		run_cmd(t_string *cmd);

/*
**	Utils
*/

int			file_wapper(char *filename, int (*func)(int fd));

#endif
