/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_fi_check_width_precision.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:50 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:50 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdbool.h>
#include <t_format_info.h>

/*
**	Get the next argument if there is a '*' flag for with or precision set.
**	The value gets stored in the info object.
*/

void			t_fi_check_width_precision(t_format_info *info, va_list *args)
{
	int	tmp_width;

	if (info->expect_width_arg)
	{
		tmp_width = (int)va_arg(*args, int);
		if (tmp_width < 0)
		{
			info->width = tmp_width * -1;
			info->left_align = true;
		}
		else
			info->width = tmp_width;
	}
	if (info->expect_precision_arg)
		info->precision = (int)va_arg(*args, int);
}
