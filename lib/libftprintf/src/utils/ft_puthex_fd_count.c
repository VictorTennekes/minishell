/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_fd_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:25 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 16:49:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <stdbool.h>
#include <utils.h>

/*
**	Output the unsigned long long 'n' to 'fd' as a hexadecimal number. Also add
**	the amount of printed chars to *'count'.
*/

int	ft_puthex_fd_count(char **tgt, unsigned long long n, bool cap, int fd)
{
	const char	*base = cap ? "0123456789ABCDEF" : "0123456789abcdef";
	int			res;

	res = 0;
	if (n < 16)
		res += ft_putchar_fd_count(tgt, (base[n]), fd);
	else
	{
		res += ft_puthex_fd_count(tgt, n / 16, cap, fd);
		res += ft_putchar_fd_count(tgt, (base[n % 16]), fd);
	}
	return (res);
}
