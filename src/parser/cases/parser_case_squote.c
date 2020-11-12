/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_squote.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:40:25 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:53:21 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_squote(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (parser->in_dquote || parser->escaped)
	{
		parser_case_rest(mshell, parser, i);
		parser->escaped = false;
	}
	else if (parser->in_squote)
		parser->in_squote = false;
	else if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_word = true;
		parser->in_squote = true;
	}
	else
		parser->in_squote = true;
	return (false);
}
