/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_unsigned.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:12 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:05:59 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>
#include <libft.h>
#include <utils.h>

/*
**	Print the unsigned int. This is only the non-whitespace part.
*/

static void			f_unsigned_print(t_format_func_args args,
		unsigned long long to_put, unsigned int print_len, int *res)
{
	int				n_zero;

	n_zero = print_len - ft_unsignedlen(to_put);
	while (n_zero > 0)
	{
		*res += ft_putchar_fd_count(args.info.tgt, '0', args.fd);
		n_zero--;
	}
	if (!(args.info.has_precision && !args.info.precision && !to_put))
		*res += ft_putunsigned_fd_count(args.info.tgt, to_put, args.fd);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
*/

static unsigned int	f_unsigned_get_print_len(t_format_info *info,
				unsigned long long to_put)
{
	size_t			og_len;
	unsigned int	res;

	og_len = ft_unsignedlen(to_put);
	res = og_len;
	if (info->has_precision && !info->precision && !to_put)
		return (0);
	if (info->has_precision && ((size_t)info->precision > og_len))
		res = info->precision;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_len ? info->width : og_len;
	return (res);
}

/*
**	The format function for formats of the type unsigned integer.
*/

int					f_unsigned(t_format_func_args args)
{
	unsigned long long	to_put;
	int					res;
	unsigned int		print_len;
	unsigned int		i;

	res = 0;
	to_put = sz_hex(args.info, args.args);
	print_len = f_unsigned_get_print_len(&args.info, to_put);
	if (args.info.left_align)
		f_unsigned_print(args, to_put, print_len, &res);
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
		f_unsigned_print(args, to_put, print_len, &res);
	return (res);
}
