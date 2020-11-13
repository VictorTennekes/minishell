/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:03 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:03 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

/*
**	Clear a list. The 'del' function is called with the 'content' pointer of
**	every node to free this memory. The 'lst' pointer will be set to NULL to
**	indicate that the list is cleared.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	**lst_tmp;
	t_list	*lst_tmp2;

	lst_tmp = lst;
	while (*lst)
	{
		del((*lst)->content);
		lst_tmp2 = *lst;
		*lst = (*lst)->next;
		free(lst_tmp2);
	}
	*lst_tmp = NULL;
}
