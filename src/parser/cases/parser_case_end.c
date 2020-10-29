/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_end.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:38:38 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:43:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_end(t_mshell *mshell, t_parser *parser, char c)
{
	(void)mshell;
	(void)c;
	if (parser->in_word)
		parser->end_word = true;
	if (parser->in_dquote || parser->in_squote)
	{
		mshell->ms_errno = ENO_UNEXEOF;
		return (true);
	}
	parser->done = true;
	return (false);
}
