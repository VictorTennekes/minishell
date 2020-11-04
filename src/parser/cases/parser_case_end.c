/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_end.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:38:38 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:52:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_end(t_mshell *mshell, t_parser *parser, size_t i)
{
	(void)mshell;
	(void)i;
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
