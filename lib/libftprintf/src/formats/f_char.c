/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_char.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:05 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 13:59:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <t_format_info.h>
#include <stdarg.h>
#include <utils.h>

/*
**	The format function for a single character. Has to take width into account.
*/

int		f_char(t_format_func_args args)
{
	char			c;
	unsigned int	i;
	int				res;

	res = 0;
	c = (char)va_arg(*args.args, int);
	if (args.info.left_align)
		res += ft_putchar_fd_count(args.info.tgt, c, args.fd);
	if (args.info.has_width)
	{
		i = 0;
		while (i < args.info.width - 1)
		{
			res += ft_putchar_fd_count(args.info.tgt, args.info.zero_pad ?
					'0' : ' ', args.fd);
			i++;
		}
	}
	if (!args.info.left_align)
		res += ft_putchar_fd_count(args.info.tgt, c, args.fd);
	return (res);
}
