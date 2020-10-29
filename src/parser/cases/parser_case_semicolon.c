/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_semicolon.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:41:00 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:43:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_semicolon(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, c);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->new_cmd = true;
	}
	return (false);
}
