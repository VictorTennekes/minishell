/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_percentage.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:09 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:03:48 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>
#include <ft_printf.h>
#include <t_format_info.h>
#include <utils.h>

/*
**	Handle the precentage format
*/

int		f_percentage(t_format_func_args args)
{
	unsigned int	i;
	int				res;

	res = 0;
	if (args.info.left_align)
		res += ft_putchar_fd_count(args.info.tgt, '%', args.fd);
	i = 0;
	if (args.info.has_width && args.info.width > 0)
	{
		while (i < args.info.width - 1)
		{
			res += ft_putchar_fd_count(args.info.tgt, args.info.zero_pad
					? '0' : ' ', args.fd);
			i++;
		}
	}
	if (!args.info.left_align)
		res += ft_putchar_fd_count(args.info.tgt, '%', args.fd);
	return (res);
}
