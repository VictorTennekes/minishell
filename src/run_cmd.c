/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:31:42 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 13:56:56 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

t_cmd	g_cmds[] = {
	//{ "", 0, builtin_exit },
	{ "echo", -1, builtin_echo },
	//{ "exit", 0, builtin_exit },
	{ NULL , 0, NULL },
};

void	run_cmd(char *cmd)
{
	char		**args;
	uint32_t	i;
	uint32_t	nargs;

	i = 0;
	while (g_cmds[i].cmd)
	{
		args = ft_split(cmd, ' ');
		if (!ft_strcmp(args[0], g_cmds[i].cmd))
		{
			nargs = ft_arrlen(args) - 1;
			if (g_cmds[i].maxargs != -1 && nargs > (uint32_t)g_cmds[i].maxargs)
				error("Invalid amount of arguments");
			g_cmds[i].func(args, nargs);
		}
		i++;
	}
}
