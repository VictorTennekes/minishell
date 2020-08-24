/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/28 16:33:21 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/08/24 18:25:37 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <libstring.h>

typedef struct	s_cmd {
	uint32_t	argc;
	t_string	*argv;
	bool		pipe;
}				t_cmd;

typedef enum	e_redir_type {
	WRITE = 0,
	APPEND = 1,
	INPUT = 2,
}				t_redir_type;

/*
**	The `redir_filenames` act are the filenames for the redirections defined in
**	`t_redir_type`. If one of these strings are not empty, it means that the
**	redirection should be performed.
*/

typedef struct	s_line {
	t_cmd		*cmds;
	t_string	redir_filenames[3];
}				t_line;

#endif
