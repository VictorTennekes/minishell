/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:15:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 19:58:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

#define ARGV_INIT_CAP (10)

/*
**	Builtin functions.
*/

//void	builtin_exit(char **args);
void	builtin_echo(uint32_t argc, char *argv[]);

/*
**	A list of all builtin commands and their corresponding functions.
*/

typedef struct	s_cmd {
	char		*cmd;
	int32_t		maxargc;
	void		(*func)(uint32_t argc, char *argv[]);
}				t_cmd;

char	**lex(char *cmd, uint32_t *argc);
char	*get_cmd(void);
void	error(char *msg);
void	prompt(void);
void	run_cmd(char *cmd);

/*
**	Utils
*/

char	*str_replace(char *str, char *to_find, char *replace, bool do_free);
int		file_wapper(char *filename, int (*func)(int fd));

#endif
