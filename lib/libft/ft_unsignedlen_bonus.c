/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsignedlen_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:40 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:40 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
**	Calculate the amount of digits in an unsigned long long if printed as a
**	decimal number.
*/

size_t	ft_unsignedlen(unsigned long long int n)
{
	size_t	res;

	if (!n)
		return (1);
	res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}
