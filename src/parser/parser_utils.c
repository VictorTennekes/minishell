/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 10:29:36 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/13 14:44:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include "cmd.h"
#include "parser.h"
#include <stdlib.h>

void	parser_replace_env(t_mshell *mshell, t_parser *parser)
{
	if (!parser->expand_env)
		return ;
	replace_env(mshell, parser->curr_word, parser->first_env_i);
	parser->expand_env = false;
	parser->first_env_i = -1;
}

void	parser_free_redir_files(t_parser *parser)
{
	size_t			i;
	t_redir_file	*files;

	i = 0;
	files = parser->redir_files.vla;
	while (i < parser->redir_files.size)
	{
		string_free(&files[i].redir_filename);
		i++;
	}
	free(files);
}
