/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:41:51 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:43:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_input(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, c);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->redir = true;
		parser->redir_type = INPUT;
	}
	return (false);
}
