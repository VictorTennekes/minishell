/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned_fd_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:22 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:22 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
**	Output the unsigned long long 'n' to 'fd'.
*/

void		ft_putunsigned_fd(unsigned long long n, int fd)
{
	if (n < 10)
		ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ft_putunsigned_fd(n / 10, fd);
		ft_putchar_fd((char)((n % 10) + '0'), fd);
	}
}
