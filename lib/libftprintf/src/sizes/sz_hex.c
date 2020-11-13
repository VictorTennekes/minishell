/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sz_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:01 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:04:52 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>

/*
**	Size conversion for hexadecimal formats.
*/

long long int	sz_hex(t_format_info info, va_list *args)
{
	if (info.has_size)
	{
		if (info.size == HH)
			return ((unsigned char)va_arg(*args, int));
		if (info.size == H)
			return ((unsigned short int)va_arg(*args, int));
		if (info.size == L)
			return ((unsigned long int)va_arg(*args, unsigned long int));
		if (info.size == LL)
			return ((unsigned long long int)va_arg(*args,
						unsigned long long int));
	}
	return ((unsigned int)va_arg(*args, unsigned int));
}
