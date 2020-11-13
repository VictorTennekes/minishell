/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_ll_fd_count.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 16:56:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <utils.h>

/*
**	Output the long long integer 'n' to 'fd'. Also add the amount of outputted
**	chars to *'count'.
*/

int	ft_putnbr_ll_fd_count(char **tgt, long long int n, int fd)
{
	int	res;

	res = 0;
	if (n == LLONG_MIN)
	{
		res += ft_putnbr_ll_fd_count(tgt, -9, fd);
		res += ft_putnbr_ll_fd_count(tgt, 223372036854775808, fd);
		return (res);
	}
	if (n < 0)
	{
		res += ft_putchar_fd_count(tgt, '-', fd);
		n *= -1;
	}
	if (n < 10)
		res += ft_putchar_fd_count(tgt, (char)(n + '0'), fd);
	else
	{
		res += ft_putnbr_ll_fd_count(tgt, n / 10, fd);
		res += ft_putchar_fd_count(tgt, (char)((n % 10) + '0'), fd);
	}
	return (res);
}
