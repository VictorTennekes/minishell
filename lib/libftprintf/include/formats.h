/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formats.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:33 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 13:57:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H
# include <t_format_info.h>

typedef struct	s_format_func_args {
	t_format_info	info;
	va_list			*args;
	int				n;
	int				fd;
}				t_format_func_args;

int				f_string(t_format_func_args args);
int				f_char(t_format_func_args args);
int				f_int(t_format_func_args args);
int				f_unsigned(t_format_func_args args);
int				f_hex(t_format_func_args args);
int				f_pointer(t_format_func_args args);
int				f_percentage(t_format_func_args args);
int				f_n(t_format_func_args args);

#endif
