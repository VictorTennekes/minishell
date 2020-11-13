/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_size.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:26:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:26:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Count the amount of nodes in a list.
**
**	@param {t_list *} node - the first node of the list
**
**	@return {size_t}
*/

size_t	lst_size(t_list *node)
{
	size_t	res;

	res = 0;
	while (node)
	{
		node = node->next;
		res++;
	}
	return (res);
}
