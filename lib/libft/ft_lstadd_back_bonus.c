/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:00 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:00 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Add the 'new' node to  the back of 'alst'. If 'alst' is null the pointer
**	will be altered to point to new, as it is now the first node in the list.
**
**	Note: this function is very inefficient if the first node of a list is
**	continuously passed to it. It is better practice to keep track of the last
**	known node in the list and pass this pointer to the function.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (*alst)
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
	else
		*alst = new;
}
