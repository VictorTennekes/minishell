/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_semicolon.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:41:00 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:53:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_semicolon(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, parser->input[i]);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->new_cmd = true;
	}
	return (false);
}
