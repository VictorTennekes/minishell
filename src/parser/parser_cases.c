/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 13:58:24 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:15:02 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parser_case_end(t_parser *parser, char c)
{
	(void)c;
	if (parser->in_word)
		parser->end_word = true;
	if (parser->in_dquote || parser->in_squote)
		return (true);
	parser->done = true;
	return (false);
}

bool	parser_case_rest(t_parser *parser, char c)
{
	if (!(parser->in_word || parser->in_dquote || parser->in_squote))
	{
		parser->in_word = true;
		parser_new_word(parser);
	}
	parser_push(parser, c);
	return (false);
}

bool	parser_case_whitespace(t_parser *parser, char c)
{
	if (parser->in_word)
	{
		parser->end_word = true;
		parser->in_word = false;
	}
	else if (parser->in_dquote || parser->in_squote)
		parser_push(parser, c);
	return (false);
}

bool	parser_case_squote(t_parser *parser, char c)
{
	if (parser->in_squote)
	{
		parser->end_word = true;
		parser->in_squote = false;
	}
	else if (parser->in_dquote)
		parser_push(parser, c);
	else if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_squote = true;
	}
	return (false);
}

bool	parser_case_dquote(t_parser *parser, char c)
{
	if (parser->in_dquote)
	{
		parser->end_word = true;
		parser->in_dquote = false;
	}
	else if (parser->in_squote)
		parser_push(parser, c);
	else if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_dquote = true;
	}
	return (false);
}
