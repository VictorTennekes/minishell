/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:24 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 15:41:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <unistd.h>
#include <utils.h>

int	ft_putchar_fd_count(char **tgt, char c, int fd)
{
	(void)tgt;
	ftp_write(&c, tgt, 1, fd);
	return (1);
}
