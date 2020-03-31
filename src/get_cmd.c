/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:16:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 15:59:43 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Reads one command from stdin. Returns the allocated string with the command.
*/

t_string	get_cmd(void)
{
	char		*res;
	t_string	str;

	if (get_next_line(0, &res) < 0)
		error(E_READ "'get_cmd'");
	if (!res)
		error(E_ALLOC "'get_cmd'");
	if (string_from(res, &str))
		error(E_ALLOC "'get_cmd'");
	free(res);
	return (str);
}
