/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_remove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:26:25 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:26:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"
#include <stdlib.h>

/*
**	Remove a node from a list.
**
**	@param {t_list *} node - the node to remove
**	@param {void (*)(void *)} free_func - the function which is called with the
**		nodes content as argument, to free it properly.
*/

void	lst_remove(t_list *node, void (*free_func)(void *))
{
	if (!node)
		return ;
	free_func(node->content);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}
