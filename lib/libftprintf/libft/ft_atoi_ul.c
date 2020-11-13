/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_ul.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:23:00 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:23:00 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		skip_ws(char **str)
{
	while ((**str == '\t' || **str == '\n' || **str == ' ' || **str == '\r' ||
			**str == '\f' || **str == '\v') && **str)
		(*str)++;
	if (**str == '+')
		(*str)++;
}

/*
**	Convert a character string to an unsigned long.
**	- returns 0 if overflow
**	- allows unlimited whitespace at the beginning of the string
**	- allows a signle '+' sign at the beginning of the string
*/

unsigned long	ft_atoi_ul(const char *str)
{
	unsigned long	res;
	unsigned long	prev_res;

	skip_ws((char **)&str);
	res = 0;
	while (*str)
	{
		prev_res = res;
		if (!ft_isdigit(*str))
			break ;
		res *= 10;
		res += *str - '0';
		if (res < prev_res)
			return (0);
		str++;
	}
	return (res);
}
