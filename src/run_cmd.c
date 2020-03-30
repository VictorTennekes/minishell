/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:31:42 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 17:23:53 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

t_cmd	g_cmds[] = {
	{ "echo", -1, builtin_echo },
	//{ "exit", 0, builtin_exit },
	{ NULL , 0, NULL },
};

static void	free_args(uint32_t argc, char *argv[])
{
	uint32_t	i;

	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void		run_cmd(char *cmd)
{
	char		**argv;
	uint32_t	argc;
	uint32_t	i;

	if (!*cmd)
		exit(0);
	i = 0;
	argv = lex(cmd, &argc);
	if (!argv)
		error("Allocation failed in 'run_cmd'");
	while (g_cmds[i].cmd)
	{
		if (ft_strcmp(argv[0], g_cmds[i].cmd))
		{
			i++;
			continue;
		}
		if (g_cmds[i].maxargc != -1 && argc > (uint32_t)g_cmds[i].maxargc)
			error("Invalid amount of arguments");
		g_cmds[i].func(argc, argv);
		i++;
	}
	free_args(argc, argv);
}
