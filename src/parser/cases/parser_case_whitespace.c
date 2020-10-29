/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_whitespace.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:40:07 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:43:37 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_whitespace(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_word)
	{
		parser->end_word = true;
		parser->in_word = false;
	}
	else if (parser->in_dquote || parser->in_squote)
		parser_push(mshell, parser, c);
	return (false);
}
