/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:41:51 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:52:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_input(t_mshell *mshell, t_parser *parser, size_t i)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, parser->input[i]);
	else if (parser->redir == true)
	{
		ms_set_error(mshell, ENO_UNEXTOK, "");
		return (true);
	}
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->redir = true;
		parser->redir_type = INPUT;
	}
	return (false);
}
