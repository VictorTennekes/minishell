/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_int.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:07 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:02:32 by aaugusti      ########   odam.nl         */
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
*/

static void			f_int_print(t_format_func_args args, long long to_put,
		unsigned int print_len, int *res)
{
	unsigned int	is_neg;
	int				n_zero;
	int				i;
	const int		fd = args.fd;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	if (is_neg || args.info.force_sign)
		*res += ft_putchar_fd_count(args.info.tgt, is_neg ? '-' : '+', fd);
	else if (args.info.has_space)
		*res += ft_putchar_fd_count(args.info.tgt, ' ', fd);
	n_zero = print_len - ((is_neg || args.info.force_sign ||
				args.info.has_space) ? 1 : 0) - ft_intlen(to_put);
	if (n_zero > 0)
	{
		i = 0;
		while (i < n_zero)
		{
			*res += ft_putchar_fd_count(args.info.tgt, '0', fd);
			i++;
		}
	}
	if (!(args.info.has_precision && !args.info.precision && !to_put))
		*res += ft_putnbr_ll_fd_count(args.info.tgt, to_put, fd);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
*/

static unsigned int	f_int_get_print_len(t_format_info info, long long to_put)
{
	size_t			og_intlen;
	unsigned int	is_neg;
	unsigned int	res;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	og_intlen = ft_intlen(to_put);
	res = og_intlen;
	if (info.has_precision && (size_t)info.precision > og_intlen)
		res = info.precision;
	if (info.has_precision && !info.precision && !to_put)
		res = 0;
	if (is_neg || info.force_sign || info.has_space)
		res++;
	if (info.has_precision && info.has_width)
		return (res);
	if (info.zero_pad && info.has_width)
		res = info.width > og_intlen ? info.width : og_intlen;
	return (res);
}

/*
**	The format function for formats of the type integer.
*/

int					f_int(t_format_func_args args)
{
	long long int	to_put;
	int				res;
	unsigned int	print_len;
	unsigned int	i;

	res = 0;
	to_put = sz_int(args.info, args.args);
	print_len = f_int_get_print_len(args.info, to_put);
	if (args.info.left_align)
		f_int_print(args, to_put, print_len, &res);
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
		f_int_print(args, to_put, print_len, &res);
	return (res);
}
