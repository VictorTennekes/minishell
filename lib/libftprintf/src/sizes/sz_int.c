/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sz_int.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:02 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:01:11 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>

/*
**	Size conversion for integer formats.
*/

long long int	sz_int(t_format_info info, va_list *args)
{
	if (info.has_size)
	{
		if (info.size == HH)
			return ((signed char)va_arg(*args, int));
		if (info.size == H)
			return ((short int)va_arg(*args, int));
		if (info.size == L)
			return ((long int)va_arg(*args, long int));
		if (info.size == LL)
			return ((long long int)va_arg(*args, long long int));
	}
	return ((int)va_arg(*args, int));
}
