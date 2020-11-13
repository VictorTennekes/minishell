/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned_fd_count.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:29 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 16:57:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/*
**	Output the unsigned long long 'n' to 'fd'. Also add the amount of printed
**	chars to *'count'.
*/

int	ft_putunsigned_fd_count(char **tgt, unsigned long long n, int fd)
{
	int	res;

	res = 0;
	if (n < 10)
		res += ft_putchar_fd_count(tgt, (char)(n + '0'), fd);
	else
	{
		ft_putunsigned_fd_count(tgt, n / 10, fd);
		ft_putchar_fd_count(tgt, (char)((n % 10) + '0'), fd);
	}
	return (res);
}
