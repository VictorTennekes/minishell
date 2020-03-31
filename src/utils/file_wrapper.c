/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:21:36 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:27:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <libftprintf.h>
#include <errno.h>
#include <string.h>

/*
**	A generic wrapper for opening files and closing them. On success, the
**	function will call 'func' with the opened fd, and return the value which
**	'func' returned. When an error is encountered a error will be printed and
**	-1 will be returned.
**
**	@param {char *} filename
**	@param {void (*)(int)} func - will be given the opened fd
**
**	@return {int} -1 on failure, otherwise the return of 'func'
*/

int		file_wapper(char *filename, int (*func)(int fd))
{
	int	fd;
	int	ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("mshell_parser_file: %s\n", strerror(errno));
		return (-1);
	}
	ret = func(fd);
	if (close(fd) < 0)
	{
		ft_printf("mshell_parser_file: %s\n", strerror(errno));
		return (-1);
	}
	return (ret);
}
