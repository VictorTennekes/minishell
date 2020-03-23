/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:31:42 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 19:26:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

t_cmd	g_cmds[] = {
	//{ "", 0, builtin_exit },
	{ "echo", -1, builtin_echo },
	//{ "exit", 0, builtin_exit },
	{ NULL , 0, NULL },
};

void	run_cmd(char *cmd)
{
	char		**argv;
	uint32_t	argc;
	uint32_t	i;

	if (!*cmd)
		exit(0);
	i = 0;
	while (g_cmds[i].cmd)
	{
		argv = ft_split(cmd, ' ');
		if (!argv)
			error("Allocation failed in 'run_cmd'");
		if (!ft_strcmp(argv[0], g_cmds[i].cmd))
		{
			argc = ft_arrlen(argv);
			if (g_cmds[i].maxargs != -1 && argc > (uint32_t)g_cmds[i].maxargs)
				error("Invalid amount of arguments");
			g_cmds[i].func(argc, &argv[1]);
		}
		i++;
	}
}
