/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:31:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/27 11:33:49 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libstring.h>
# include <minishell.h>

int		mshell_parser_file(t_mshell *mshell, char *filename);
int		mshell_parser_single(t_mshell *mshell, t_string *line);
int		mshell_parser_rand(void);

#endif
