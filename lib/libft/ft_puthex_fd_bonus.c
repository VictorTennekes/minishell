/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_fd_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:18 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:18 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/*
**	Write the hexadecimal representation of 'n' to 'fd'. 'cap' is there to de-
**	fine whether the printed alphabetical chars should be capitalized or not.
*/

void		ft_puthex_fd(unsigned long long n, int fd, int cap)
{
	size_t	n_len;
	char	res[17];
	size_t	i;
	char	*bases;

	bases = cap ? "0123456789ABCDEF" : "0123456789abcdef";
	n_len = ft_hexlen(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	i = 0;
	res[n_len] = '\0';
	while (i < n_len)
	{
		res[n_len - 1 - i] = bases[n % 16];
		n /= 16;
		i++;
	}
	ft_putstr_fd(res, fd);
}
