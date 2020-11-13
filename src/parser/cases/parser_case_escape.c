/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_escape.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:42:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/13 10:58:10 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_escape(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_word = true;
		parser->escaped = true;
	}
	else if (!parser->in_squote)
	{
		if (parser->escaped)
		{
			parser_push(mshell, parser, parser->input[i]);
			parser->escaped = false;
		}
		else
		{
			parser_replace_env(mshell, parser);
			parser->escaped = true;
		}
	}
	else
		parser_push(mshell, parser, parser->input[i]);
	return (false);
}
