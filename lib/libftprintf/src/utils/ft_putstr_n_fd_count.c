/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_n_fd_count.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:28 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 15:45:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

int	ft_putstr_n_fd_count(char **tgt, char *str, size_t n, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > n)
		len = n;
	return (ftp_write(str, tgt, len, fd));
}
