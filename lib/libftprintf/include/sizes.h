/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sizes.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:39 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 14:04:56 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZES_H
# define SIZES_H
# include <t_format_info.h>
# include <stdarg.h>

long long int	sz_int(t_format_info info, va_list *args);
long long int	sz_hex(t_format_info info, va_list *args);

#endif
