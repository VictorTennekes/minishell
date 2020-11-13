/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_string.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:11 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:03:32 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>
#include <utils.h>

/*
**	Output the string
*/

static void			f_string_putstr(t_format_func_args args, char *str,
		int *res)
{
	if (args.info.has_precision)
		*res += ft_putstr_n_fd_count(args.info.tgt, str,
				(size_t)args.info.precision, args.fd);
	else
		*res += ft_putstr_fd_count(args.info.tgt, str, args.fd);
}

/*
**	Pring the right amount and the right type of padding before or after the
**	string.
*/

static unsigned int	f_string_print_padding(t_format_func_args args,
		unsigned int str_len, int *res)
{
	unsigned int	i;

	i = 0;
	if (args.info.has_width && args.info.width > str_len)
	{
		while (i < args.info.width - str_len)
		{
			*res += ft_putchar_fd_count(args.info.tgt, args.info.zero_pad
					? '0' : ' ', args.fd);
			i++;
		}
	}
	return (i);
}

/*
**	Get the strings length and take precision into account.
*/

static unsigned int	f_string_get_strlen(t_format_info *info, char *str)
{
	size_t	og_str_len;

	if (str == NULL)
		return (0);
	og_str_len = ft_strlen(str);
	if (info->has_precision && info->precision > 0 &&
			og_str_len > (size_t)info->precision)
		return (info->precision);
	return (og_str_len);
}

/*
**	Function to output a string with different format rules.
*/

int					f_string(t_format_func_args args)
{
	char			*str;
	unsigned int	str_len;
	int				res;

	res = 0;
	str = (char *)va_arg(*args.args, char *);
	if (str == NULL)
		str = "(null)";
	str_len = f_string_get_strlen(&args.info, str);
	if (args.info.left_align)
		f_string_putstr(args, str, &res);
	f_string_print_padding(args, str_len, &res);
	if (!args.info.left_align)
		f_string_putstr(args, str, &res);
	return (res);
}
