/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcount_condition_bonus.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:05 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Count the amount of times 'f' returns 1 if every 'content' of every node in
**	'lst' is passed to it.
*/

int	ft_lstcount_condition(t_list *lst, int (*f)(void *))
{
	int	res;

	res = 0;
	while (lst)
	{
		if (f(lst->content))
			res++;
		lst = lst->next;
	}
	return (res);
}
