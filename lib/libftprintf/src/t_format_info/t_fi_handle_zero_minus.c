/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_fi_handle_zero_minus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:56 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:56 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <stdbool.h>

/*
**	Disable zero pad when left align is active
*/

void	t_fi_handle_zero_minus(t_format_info *info)
{
	if (info->left_align)
		info->zero_pad = false;
}
