/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_rest.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:39:44 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:53:06 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_rest(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (!(parser->in_word || parser->in_dquote || parser->in_squote))
	{
		parser->in_word = true;
		parser_new_word(mshell, parser);
	}
	if (parser->escaped)
	{
		if ((parser->in_dquote || parser->in_squote))
			if (parser->input[i] != '$')
				parser_push(mshell, parser, '\\');
		parser->escaped = false;
	}
	parser_push(mshell, parser, parser->input[i]);
	return (false);
}
