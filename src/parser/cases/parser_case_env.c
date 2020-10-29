/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_case_env.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:42:02 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:43:23 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../parser.h"

bool	parser_case_env(t_mshell *mshell, t_parser *parser, char c)
{
	parser->expand_env = !parser->in_squote;
	parser_case_rest(mshell, parser, c);
	return (false);
}
