/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_escape.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:42:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/04 15:16:22 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_escape(t_mshell *mshell, t_parser *parser, char c)
{
	if (!parser->in_squote)
	{
		if (parser->escaped)
		{
			parser_push(mshell, parser, c);
			parser->escaped = false;
			return (false);
		}
		parser->escaped = true;
		return (false);
	}
	return (parser_case_rest(mshell, parser, c));
}
