/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_env.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:42:02 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/13 10:39:23 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"
#include "libft.h"
#include "env.h"

bool	parser_case_env(t_mshell *mshell, t_parser *parser, size_t i)
{
	char	next_char;
	
	next_char = parser->input[i + 1];
	if ((next_char == '"' || next_char == '\'') &&
			!(parser->in_squote || parser->in_dquote))
		return (false);
	if (parser->escaped || parser->in_squote ||
			(next_char == '"' && parser->in_dquote))
	{
		parser_case_rest(mshell, parser, i);
		return (false);
	}
	if (!parser->in_squote)
	{
		parser->expand_env = true;
		if (parser->first_env_i == -1)
			parser->first_env_i = parser->curr_word == NULL
				? 0 : parser->curr_word->len;
	}
	parser_case_rest(mshell, parser, i);
	return (false);
}
