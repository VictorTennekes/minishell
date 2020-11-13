/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:31 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 15:44:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <ft_printf.h>
#include <unistd.h>

int	write_string(char **tgt, char **format, int fd)
{
	size_t	len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	ft_putstr_n_fd_count(tgt, *format, len, fd);
	(*format) += len;
	return ((int)len);
}
