/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:16:57 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 13:26:09 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <minishell.h>

/*
**	Reads one command from stdin. Returns the allocated string with the command.
*/

char	*get_cmd(void)
{
	char	*res;

	if (get_next_line(0, &res) < 0)
		error("Read failed in 'get_cmd'");
	if (!res)
		error("Allocation failed in 'get_cmd'");
	return (res);
}
