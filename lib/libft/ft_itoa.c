/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:15:59 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:15:59 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/*
**	Get the amount of bytes needed to store the result of itoa.
*/

static int	ft_itoa_numlen(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n *= -1;
		res++;
	}
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

/*
**	Check for the two edgecases and handle those.
*/

static char	*ft_itoa_exception(int n)
{
	if (n)
		return (ft_strdup("-2147483648"));
	return (ft_strdup("0"));
}

/*
**	Allocate the right amount of memory for the result string and zero-temrinate
**	the string.
*/

static char	*ft_itoa_get_mem(size_t len)
{
	char	*res;

	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	res[len - 1] = '\0';
	return (res);
}

/*
**	Convert an integer into a string. Returns NULL if the allocation failed.
*/

char		*ft_itoa(int n)
{
	int		n_len;
	int		is_neg;
	char	*res;
	int		i;

	if (n == INT_MIN || n == 0)
		return (ft_itoa_exception(n));
	n_len = ft_itoa_numlen(n);
	res = ft_itoa_get_mem((size_t)n_len + 1);
	if (res == NULL)
		return (NULL);
	is_neg = n < 0;
	if (is_neg)
	{
		*res = '-';
		n *= -1;
	}
	i = 0;
	while (i < n_len - is_neg)
	{
		res[n_len - 1 - i] = (char)(n % 10 + '0');
		n /= 10;
		i++;
	}
	return (res);
}
