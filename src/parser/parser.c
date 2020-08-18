/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 19:49:13 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/18 16:27:42 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <libft.h>
#include <libvla.h>
#include <minishell.h>
#include <stdlib.h>

t_parser_case	g_parser_cases[] = {
	{ '\0',	parser_case_end },
	{ ' ',	parser_case_whitespace },
	{ '\t',	parser_case_whitespace },
	{ '\'',	parser_case_squote },
	{ '\"',	parser_case_dquote },
	{ ';',	parser_case_semicolon },
	{ 42,	NULL },
};

static t_parser	parser_new(t_mshell *mshell)
{
	t_parser	res;

	ft_bzero(&res, sizeof(t_parser));
	if (vla_init(sizeof(t_cmd), PARSER_CMDS_INIT_CAP, &res.result))
		error(E_ALLOC "'new_parser'", mshell);
	return (res);
}

static bool		parser_step(t_mshell *mshell, t_parser *parser, char c)
{
	uint32_t	i;

	i = 0;
	while (g_parser_cases[i].func != NULL)
	{
		if (g_parser_cases[i].c == c)
			return (g_parser_cases[i].func(mshell, parser, c));
		i++;
	}
	return (parser_case_rest(mshell, parser, c));
}

static t_cmd	*parser_return(t_mshell *mshell, t_parser *parser,
					size_t *cmd_count)
{
	if (parser->curr_cmd.size > 0)
		parser_push_cmd(mshell, parser);
	if (vla_shrink(&parser->result))
		error(E_ALLOC "'parser_return'", mshell);
	*cmd_count = parser->result.size;
	return(parser->result.vla);
}

t_cmd		*parser(t_mshell *mshell, char *cmd, size_t *cmd_count)
{
	t_parser	parser;
	size_t		i;

	parser = parser_new(mshell);
	parser_new_cmd(mshell, &parser, true);
	i = 0;
	while (42)
	{
		if (parser_step(mshell, &parser, cmd[i]))
			error("Invalid input", mshell);
		if (parser.new_word)
			parser_new_word(mshell, &parser);
		if (parser.end_word)
			parser_end_word(mshell, &parser);
		if (parser.new_cmd)
			parser_new_cmd(mshell, &parser, false);
		if (parser.done)
			return (parser_return(mshell, &parser, cmd_count));
		i++;
	}
}
