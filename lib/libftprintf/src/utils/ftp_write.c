/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_write.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:30 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 16:24:04 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>

/*
**	The function which writes the characters to the output of the function.
**	This can either be stdout or a char buffer.
*/

int	ftp_write(char *to_write, char **target, size_t n, int fd)
{
	int	write_return;

	if (target)
	{
		ft_memcpy(*target, to_write, n);
		(*target) += sizeof(char) * n;
	}
	else
	{
		write_return = write(fd, to_write, n);
		if (write_return == -1)
			return (n);
	}
	return (n);
}
