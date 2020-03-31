/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 19:49:13 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:14:04 by aaugusti         ###   ########.fr       */
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
	{ 42,	NULL },
};

t_parser		new_parser(void)
{
	t_parser	res;

	ft_bzero(&res, sizeof(t_parser));
	if (vla_init(sizeof(t_string), PARSER_ARGV_INIT_CAP, &res.result))
		error(E_ALLOC "'new_parser'");
	return (res);
}

bool		parser_step(t_parser *parser, char c)
{
	uint32_t	i;

	i = 0;
	while (g_parser_cases[i].func != NULL)
	{
		if (g_parser_cases[i].c == c)
			return (g_parser_cases[i].func(parser, c));
		i++;
	}
	return (parser_case_rest(parser, c));
}

t_string	*parser_return(t_parser *parser, uint32_t *argc)
{
	vla_shrink(&parser->result);
	*argc = parser->argc;
	return(parser->result.vla);
}

t_string	*parser(t_string *cmd, uint32_t *argc)
{
	t_parser		parser;
	uint32_t	i;

	parser = new_parser();
	i = 0;
	while (42)
	{
		if (parser_step(&parser, cmd->str[i]))
			error("Invalid input");
		if (parser.new_word)
			parser_new_word(&parser);
		if (parser.end_word)
			parser_end_word(&parser);
		if (parser.done)
			return (parser_return(&parser, argc));
		i++;
	}
}
