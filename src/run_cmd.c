/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:31:42 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:54:10 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

t_cmd	g_cmds[] = {
	{ "echo", 	builtin_echo },
	{ "exit", 	builtin_exit },
	{ NULL , 	NULL },
};

static void	free_args(uint32_t argc, t_string argv[])
{
	uint32_t	i;

	i = 0;
	while (i < argc)
	{
		string_free(&argv[i]);
		i++;
	}
	free(argv);
}

void		run_cmd(t_string *cmd)
{
	t_string	*argv;
	uint32_t	argc;
	uint32_t	i;

	if (!*cmd->str)
		exit(0);
	i = 0;
	argv = parser(cmd, &argc);
	if (!argv)
		error(E_ALLOC "'run_cmd'");
	while (g_cmds[i].cmd)
	{
		if (ft_strcmp(argv[0].str, g_cmds[i].cmd))
		{
			i++;
			continue;
		}
		//TODO handle a 'true' return
		g_cmds[i].func(argc, argv);
		i++;
	}
	free_args(argc, argv);
}
