/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_hex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:06 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:05:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <stdarg.h>
#include <t_format_info.h>
#include <libft.h>
#include <utils.h>
#include <sizes.h>

/*
**	Print the integer. This is only the non-whitespace part of the int.
**	- first check negative; the first char in the case of a negative int is
**		always a minus
*/

static void			f_hex_print(t_format_func_args args,
		unsigned long long to_put, unsigned int print_len, int *res)
{
	int				n_zero;

	if (args.info.has_precision && !args.info.precision && !to_put &&
			args.info.type != POINTER)
		return ;
	if (args.info.hex_identifier)
		*res += ft_putstr_fd_count(args.info.tgt, args.info.type == HEX_UP
				? "0X" : "0x", args.fd);
	n_zero = print_len - ft_hexlen(to_put) - ((args.info.hex_identifier &&
		(to_put || args.info.type == POINTER)) ? 2 : 0);
	while (n_zero > 0)
	{
		*res += ft_putchar_fd_count(args.info.tgt, '0', args.fd);
		n_zero--;
	}
	if (!(args.info.has_precision && !args.info.precision && !to_put &&
			args.info.type == POINTER))
		*res += ft_puthex_fd_count(args.info.tgt, to_put,
				args.info.type == HEX_UP, args.fd);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
**	- in the case that width is set and there is a zero flag return the largest
**		of og_hexlen and width.
**	- if precision is set and precision is larger than og_hexlen return pre-
**		cision.
**		* also, if to_put is negative add a byte for the minus
**	- precision overwrites width
*/

static unsigned int	f_hex_get_print_len(t_format_info *info,
		unsigned long long to_put)
{
	size_t			og_hexlen;
	unsigned int	res;

	og_hexlen = ft_hexlen(to_put);
	res = og_hexlen;
	if (info->has_precision && !info->precision && !to_put)
		res = 0;
	if (info->has_precision && ((size_t)info->precision > og_hexlen))
		res = info->precision;
	if (info->hex_identifier)
		res += 2;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_hexlen ? info->width : og_hexlen;
	return (res);
}

/*
**	The format function for formats of the type unsigned integer printed as hex.
**	Also implements support for pointers.
*/

int					f_hex(t_format_func_args args)
{
	unsigned long long	to_put;
	int					res;
	unsigned int		print_len;
	unsigned int		i;

	res = 0;
	to_put = sz_hex(args.info, args.args);
	if (!to_put && args.info.type != POINTER)
		args.info.hex_identifier = false;
	print_len = f_hex_get_print_len(&args.info, to_put);
	if (args.info.left_align)
		f_hex_print(args, to_put, print_len, &res);
	if (args.info.width > print_len)
	{
		i = 0;
		while (i < args.info.width - print_len)
		{
			res += ft_putchar_fd_count(args.info.tgt, ' ', args.fd);
			i++;
		}
	}
	if (!args.info.left_align)
		f_hex_print(args, to_put, print_len, &res);
	return (res);
}
