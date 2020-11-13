/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:15:19 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:15:19 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function to handle the whitespaces, '+' and '-' chars at the start of a
**	atoi string. A pointer to the string and a pointer to a t_bool is given to
**	store the 'is_neg' value is given.
**	Returns 0 if the string is valid so far, 1 if this is not the case.
*/

static t_bool	ft_atoi_skip_ws(char **str, t_bool *is_neg)
{
	int	has_plus;

	has_plus = 0;
	while ((**str == '\t' || **str == '\n' || **str == ' ' || **str == '\r' ||
			**str == '\f' || **str == '\v') && **str)
		(*str)++;
	if (**str == '+')
	{
		(*str)++;
		has_plus = 1;
	}
	if (**str == '-')
	{
		if (has_plus)
			return (1);
		*is_neg = -1;
		(*str)++;
	}
	return (0);
}

/*
**	Convert ASCII string to integer
**		_a copy of the libc function_
**
**	Integer overflow is 'allowed'. The function does the conversion to a un-
**	signed long and casts it back when returning. When the long overflows the
**	function returns -1 if the value was negative and 0 if it was not.
**
**	All whitespaces at the beginning of the string are skipped and there is a
**	single sign allowed. The conversion stops when the first non-digit char is
**	encountered and the current result value is returned.
*/

int				ft_atoi(const char *str)
{
	t_bool				is_neg;
	unsigned long int	res;
	unsigned long int	prev_res;

	is_neg = 1;
	if (ft_atoi_skip_ws((char **)&str, &is_neg))
		return (0);
	res = 0;
	while (ft_isdigit(*str))
	{
		prev_res = res;
		res *= 10;
		res += *str - '0';
		if (prev_res > res)
			return (is_neg == -1 ? 0 : -1);
		str++;
	}
	return ((int)res * is_neg);
}
