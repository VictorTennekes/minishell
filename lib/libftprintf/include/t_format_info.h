/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_format_info.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:40 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:41 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FORMAT_INFO_H
# define T_FORMAT_INFO_H

# include "../libft/libft.h"
# include "t_size.h"
# include "t_var_type.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct		s_format_info
{
	bool			expect_precision_arg;
	bool			expect_width_arg;
	bool			force_sign;
	bool			has_precision;
	bool			has_size;
	bool			has_space;
	bool			has_width;
	bool			hex_identifier;
	bool			left_align;
	bool			zero_pad;
	char			**tgt;
	int				precision;
	t_size			size;
	t_var_type		type;
	unsigned int	width;
}					t_format_info;

void				t_fi_get_info(t_format_info	*info, char **format);
void				t_fi_check_width_precision(t_format_info *info,
		va_list *args);
void				t_fi_handle_plus_space(t_format_info *info);
void				t_fi_handle_zero_minus(t_format_info *info);

#endif
