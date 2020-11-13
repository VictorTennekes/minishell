/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:38 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <t_format_info.h>

void	flags(t_format_info *info, char **format);
void	width(t_format_info *info, char **format);
void	precision(t_format_info *info, char **format);
int		specifier(t_format_info *info, char **format);
void	size(t_format_info *info, char **format);

#endif
