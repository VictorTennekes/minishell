/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:35:16 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:35:31 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "../run_cmd/run_cmd.h"

#define EX_SYNTAX

static bool	parser_check_pipe(t_mshell *mshell, t_cmd **result,
		size_t *cmd_count)
{
	if ((*result)[*cmd_count - 1].pipe == false)
		return (false);
	ms_set_error(mshell, ENO_UNEXEOF, "syntax error");
	return (true);
}

t_parser_check	g_checks[] = {
	parser_check_pipe,
	NULL,
};

void		parser_check(t_mshell *mshell, t_cmd **result, size_t *cmd_count)
{
	size_t	i;
	bool	check_ret;

	i = 0;
	while (g_checks[i] != NULL)
	{
		check_ret = g_checks[i](mshell, result, cmd_count);
		if (check_ret)
		{
			free_cmds(*result, *cmd_count);
			*result = NULL;
			*cmd_count = 0;
			return ;
		}
		i++;
	}
}
