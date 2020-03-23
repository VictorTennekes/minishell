/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:15:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 19:04:19 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

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
	int32_t		maxargs;
	void		(*func)(uint32_t argc, char *argv[]);
}				t_cmd;

char	*get_cmd(void);
void	error(char *msg);
void	prompt(void);
void	run_cmd(char *cmd);

#endif
