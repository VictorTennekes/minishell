/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_squote.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:40:25 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:43:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_squote(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_dquote || parser->escaped)
	{
		if (parser->in_dquote)
			parser_push(mshell, parser, '\\');
		parser_push(mshell, parser, c);
		parser->escaped = false;
	}
	else if (parser->in_squote)
	{
		parser->end_word = true;
		parser->in_squote = false;
	}
	else if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_squote = true;
	}
	return (false);
}
