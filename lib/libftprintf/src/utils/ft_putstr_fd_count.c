/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 13:33:06 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

int	ft_putstr_fd_count(char **tgt, char *str, int fd)
{
	const size_t	len = ft_strlen(str);

	return (ftp_write(str, tgt, len, fd));
}
