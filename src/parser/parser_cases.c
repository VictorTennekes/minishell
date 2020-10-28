/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_cases.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 13:58:24 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/18 15:41:02 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>

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

bool	parser_case_rest(t_mshell *mshell, t_parser *parser, char c)
{
	if (!(parser->in_word || parser->in_dquote || parser->in_squote))
	{
		parser->in_word = true;
		parser_new_word(mshell, parser);
	}
	parser_push(mshell, parser, c);
	return (false);
}

bool	parser_case_whitespace(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_word)
	{
		parser->end_word = true;
		parser->in_word = false;
	}
	else if (parser->in_dquote || parser->in_squote)
		parser_push(mshell, parser, c);
	return (false);
}

bool	parser_case_squote(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_squote)
	{
		parser->end_word = true;
		parser->in_squote = false;
	}
	else if (parser->in_dquote)
		parser_push(mshell, parser, c);
	else if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_squote = true;
	}
	return (false);
}

bool	parser_case_dquote(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_dquote)
	{
		parser->end_word = true;
		parser->in_dquote = false;
	}
	else if (parser->in_squote)
		parser_push(mshell, parser, c);
	else if (!parser->in_word)
	{
		parser->new_word = true;
		parser->in_dquote = true;
	}
	return (false);
}

bool	parser_case_semicolon(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, c);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->new_cmd = true;
	}
	return (false);
}

bool	parser_case_pipe(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, c);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		parser->new_cmd = true;
		parser->pipe = true;
	}
	return (false);
}

bool	parser_case_write(t_mshell *mshell, t_parser *parser, char c)
{
	if (parser->in_squote || parser->in_dquote)
		parser_push(mshell, parser, c);
	else
	{
		if (parser->in_word)
			parser->end_word = true;
		if (parser->redir == true && parser->redir_type == APPEND)
		{
			ms_set_error(mshell, ENO_UNEXTOK, "");
			return (true);
		}
		else if (parser->redir == true)
			parser->redir_type = APPEND;
		else {
			parser->redir = true;
			parser->redir_type = WRITE;
		}
	}
	return (false);
}

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

bool	parser_case_env(t_mshell *mshell, t_parser *parser, char c)
{
	parser->expand_env = !parser->in_squote;
	parser_case_rest(mshell, parser, c);
	return (false);
}
