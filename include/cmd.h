/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/28 16:33:21 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/09 14:54:19 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "liblist.h"
# include <libstring.h>

typedef enum		e_redir_type {
	WRITE = 0,
	APPEND = 1,
	INPUT = 2,
}					t_redir_type;

typedef struct		s_redir_file {
	t_string		redir_filename;
	t_redir_type	redir_type;
}					t_redir_file;

typedef struct		s_cmd {
	size_t			argc;
	t_string		*argv;
	t_redir_file	*redir_files;
	size_t			redir_count;
	bool			pipe;
}					t_cmd;

typedef struct		s_cmd_directions {
	bool	has_redirect[3];
	int		redirect_fd[3];
}					t_cmd_directions;

#endif
