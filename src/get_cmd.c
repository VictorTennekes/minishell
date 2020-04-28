/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:16:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/27 11:29:02 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Reads one command from stdin. Returns the allocated string with the command.
**
**	@param {t_mshell *} mshell - Used for the errors
*/

t_string	get_cmd(t_mshell *mshell)
{
	char		*res;
	t_string	str;

	if (get_next_line(0, &res) < 0)
		error(E_READ "'get_cmd'", mshell);
	if (!res)
		error(E_ALLOC "'get_cmd'", mshell);
	if (string_from(res, &str))
		error(E_ALLOC "'get_cmd'", mshell);
	free(res);
	return (str);
}
