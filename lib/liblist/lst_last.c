/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_last.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:26:21 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:27:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Get the last element in a list.
**
**	@param {t_list *} list
**
**	@return {t_list *}
*/

t_list	*lst_last(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}
