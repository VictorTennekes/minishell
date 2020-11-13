/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_fi_parse_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:57 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <stdbool.h>
#include <t_format_info.h>

/*
**	Deal with the flags.
**	- Skips the '%' char
**	- Loops through the flags and sets the appropiate variable until another
**		character is encountered
*/

void	flags(t_format_info *info, char **format)
{
	(*format)++;
	while (**format)
	{
		if (**format == '-')
			info->left_align = true;
		else if (**format == '0')
			info->zero_pad = true;
		else if (**format == '+')
			info->force_sign = true;
		else if (**format == '#')
			info->hex_identifier = true;
		else if (**format == ' ')
			info->has_space = true;
		else
			return ;
		(*format)++;
	}
}

/*
**	Deal with the width parameter.
**	- Just calls atoi on the format. Atoi will automatically stop when a
**		non-digit char is encountered.
*/

void	width(t_format_info *info, char **format)
{
	int	width;

	if (**format == '*')
	{
		info->expect_width_arg = true;
		info->has_width = true;
		(*format)++;
		return ;
	}
	width = ft_atoi(*format);
	if (width > 0)
	{
		info->width = width;
		info->has_width = true;
		while (ft_isdigit(**format))
			(*format)++;
	}
}

/*
**	Deal with the precision parameter
**	- will check for a period
**	- check for an asterisk
**	- just run atoi
**
**	! should be interpreted as a non-negative decimal integer
*/

void	precision(t_format_info *info, char **format)
{
	unsigned int	precision;

	if (**format != '.')
		return ;
	info->has_precision = true;
	(*format)++;
	if (**format == '*')
	{
		info->expect_precision_arg = true;
		(*format)++;
		return ;
	}
	precision = ft_atoi_ul(*format);
	info->precision = precision;
	while (ft_isdigit(**format))
		(*format)++;
}

t_var_type	g_specifier_types[] = {
	[(int)'s'] = STRING,
	[(int)'c'] = CHAR,
	[(int)'i'] = INT,
	[(int)'d'] = INT,
	[(int)'%'] = PERCENTAGE,
	[(int)'X'] = HEX_UP,
	[(int)'x'] = HEX_LOW,
	[(int)'p'] = POINTER,
	[(int)'u'] = UNSIGNED,
	[(int)'n'] = N,
};

/*
**	Parse the specifier for the format string
**	Returns a 0 if a valid specifier was found, 1 if there was none
*/

int		specifier(t_format_info *info, char **format)
{
	if (!ft_strchr("scidXxpun%", **format))
		return (1);
	info->type = g_specifier_types[(int)**format];
	(*format)++;
	return (0);
}

/*
**	Retrieves the size flag for format strings.
*/

void	size(t_format_info *info, char **format)
{
	if (**format == 'l')
	{
		info->has_size = true;
		if ((*format)[1] == 'l')
		{
			info->size = LL;
			(*format)++;
		}
		else
			info->size = L;
		(*format)++;
		return ;
	}
	if (**format == 'h')
	{
		info->has_size = true;
		if ((*format)[1] == 'h')
		{
			info->size = HH;
			(*format)++;
		}
		else
			info->size = H;
		(*format)++;
	}
}
