/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_pipe.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:41:16 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:52:59 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_pipe(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (parser->in_squote || parser->in_dquote || parser->escaped)
		parser_case_rest(mshell, parser, i);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->new_cmd = true;
		parser->pipe = true;
	}
	return (false);
}
