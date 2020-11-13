/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 10:29:36 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/13 10:36:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include "parser.h"

void	parser_replace_env(t_mshell *mshell, t_parser *parser)
{
	if (!parser->expand_env)
		return ;
	replace_env(mshell, parser->curr_word, parser->first_env_i);
	parser->expand_env = false;
	parser->first_env_i = -1;
}
