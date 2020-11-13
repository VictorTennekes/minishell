/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:26:22 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:26:22 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"
#include <stdlib.h>

/*
**	Create a new node.
**
**	@param {void *} content - a pointer to the content of the node
**
**	@return {t_list *} - a pointer to the new node. NULL if an error occured
*/

t_list	*lst_new(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
