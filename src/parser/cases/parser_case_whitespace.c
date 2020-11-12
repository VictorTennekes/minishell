/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_whitespace.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:40:07 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:53:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_whitespace(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (parser->in_dquote || parser->in_squote)
		parser_push(mshell, parser, parser->input[i]);
	else if (parser->in_word)
	{
		parser->end_word = true;
		parser->in_word = false;
	}
	return (false);
}
