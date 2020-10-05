/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 14:02:02 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/04/28 20:08:31 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <libstring.h>
#include <minishell.h>

void		parser_push(t_mshell *mshell, t_parser *parser, char c)
{
	if (string_pushc(parser->curr_word, c))
		error(E_ALLOC "'parser_push'", mshell);
}

void		parser_new_word(t_mshell *mshell, t_parser *parser)
{
	t_string		new;
	t_string		*new_loc;
	t_redir_file	new_file;

	if (parser->redir)
	{
		if (string_init(PARSER_INIT_WORD_CAP, NULL, &new_file.redir_filename[parser->redir_kind]))
			error(E_ALLOC "'parser_new_word'", mshell);
		if (vla_push(&parser->redir_files, &new_file.redir_filename[parser->redir_kind], (void **)&new_loc))
			error(E_ALLOC "'parser_new_word'", mshell);
		parser->redir = false;
	}
	else
	{
		if (string_init(PARSER_INIT_WORD_CAP, NULL, &new))
			error(E_ALLOC "'parser_new_word'", mshell);
		if (vla_push(&parser->curr_cmd, &new, (void **)&new_loc))
			error(E_ALLOC "'parser_new_word'", mshell);
	}
	parser->curr_word = new_loc;
	parser->new_word = false;
}

void		parser_end_word(t_mshell *mshell, t_parser *parser)
{
	if (string_shrink(parser->curr_word))
		error(E_ALLOC "'parser_end_word'", mshell);
	parser->curr_word = NULL;
	parser->end_word = false;
	parser->in_word = false;
}

void		parser_push_cmd(t_mshell *mshell, t_parser *parser)
{
	t_cmd	to_push;

	if (vla_shrink(&parser->curr_cmd))
		error(E_ALLOC "'parser_new_cmd'", mshell);
	to_push.argv = parser->curr_cmd.vla;
	to_push.argc = parser->curr_cmd.size;
	to_push.pipe = parser->pipe;
	to_push.redir_files = parser->redir_files.vla;
	if (vla_push(&parser->result, &to_push, NULL))
		error(E_ALLOC "'parser_new_cmd'", mshell);
}

// ABE FIX MY BIG POOPOO CODE

void		parser_new_cmd(t_mshell *mshell, t_parser *parser, bool init)
{
	if (!init)
		parser_push_cmd(mshell, parser);
	if (vla_init(sizeof(t_string), PARSER_ARGV_INIT_CAP,
				&parser->curr_cmd))
		error(E_ALLOC "'parser_new_cmd'", mshell);
	if (vla_init(sizeof(t_redir_file), PARSER_FILES_INIT_CAP, &parser->redir_files))
		error(E_ALLOC "'parser_new_cmd'", mshell);
	parser->new_cmd = false;
	parser->pipe = false;
}
