/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:16:57 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 16:17:50 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Reads one command from stdin. Returns the allocated string with the command.
**
**	@param {t_mshell *} mshell - Used for the errors
**
**	@return {char *}
*/

char	*get_cmd(t_mshell *mshell)
{
	char		*res;

	if (get_next_line(0, &res) < 0)
		error(E_GNL "'get_cmd'", mshell);
	return (res);
}
