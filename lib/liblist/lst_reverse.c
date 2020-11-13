/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_reverse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:26:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:26:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Reverse a linked list.
**
**	@param {t_list **} node - a pointer to the start of the list. The pointer
**		to the new beginning of the list will be stored here.
*/

void	lst_reverse(t_list **node)
{
	t_list	*node_cpy;
	t_list	*tmp;

	if (!node)
		return ;
	if (!*node)
		return ;
	node_cpy = *node;
	tmp = NULL;
	while (node_cpy)
	{
		tmp = node_cpy->prev;
		node_cpy->prev = node_cpy->next;
		node_cpy->next = tmp;
		node_cpy = node_cpy->prev;
	}
	*node = tmp->prev;
}
