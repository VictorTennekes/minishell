/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:19 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 13:59:02 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>
#include <ft_printf.h>
#include <stdarg.h>
#include <t_format_info.h>

int	(*g_format_functions[])(t_format_func_args) = {
	[CHAR] = f_char,
	[STRING] = f_string,
	[POINTER] = f_pointer,
	[INT] = f_int,
	[UNSIGNED] = f_unsigned,
	[HEX_LOW] = f_hex,
	[HEX_UP] = f_hex,
	[PERCENTAGE] = f_percentage,
	[N] = f_n,
};

int		output(t_format_func_args args)
{
	return (g_format_functions[args.info.type](args));
}
