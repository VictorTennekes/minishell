/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:31:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:17:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libstring.h>

int		mshell_parser_file(char *filename);
int		mshell_parser_single(t_string *line);
int		mshell_parser_rand(void);

#endif
