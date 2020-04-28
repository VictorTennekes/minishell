/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/28 16:33:21 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 16:34:09 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <libstring.h>

typedef struct	s_cmd {
	uint32_t	argc;
	t_string	*argv;
}				t_cmd;

#endif
