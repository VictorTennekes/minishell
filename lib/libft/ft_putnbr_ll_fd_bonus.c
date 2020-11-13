/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_ll_fd_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:19 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:19 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
**	Output the long long integer 'n' to 'fd'.
*/

void		ft_putnbr_ll_fd(long long int n, int fd)
{
	if (n == LLONG_MIN)
	{
		ft_putnbr_ll_fd(-9, fd);
		ft_putnbr_ll_fd(223372036854775808, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ft_putnbr_ll_fd(n / 10, fd);
		ft_putchar_fd((char)((n % 10) + '0'), fd);
	}
}
