/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_ui_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:15:20 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:15:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
**	Convert a character string to an unsigned int.
**	- returns 0 if overflow
**	- allows unlimited whitespace at the beginning of the string
**	- allows a signle '+' sign at the beginning of the string
*/

unsigned int	ft_atoi_ui(const char *str)
{
	unsigned int	res;

	res = (unsigned int)ft_atoi_ul(str);
	if (res > UINT_MAX)
		return (0);
	return ((unsigned int)res);
}
