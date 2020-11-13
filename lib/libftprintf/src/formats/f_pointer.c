/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_pointer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:10 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:05:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>

/*
**	This is just a wrapper around f_hex, which sets some additional flags to
**	format the pointer correctly.
*/

int		f_pointer(t_format_func_args args)
{
	args.info.hex_identifier = true;
	args.info.has_size = true;
	args.info.size = LL;
	return (f_hex(args));
}
