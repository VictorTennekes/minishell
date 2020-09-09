/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:14:58 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/18 14:57:55 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
#include <env.h>

#include <stdio.h>

int	main(void)
{
	t_mshell	mshell;
	char		*cmd;

	init(&mshell);
	while (1)
	{
		env_set(&mshell, "?", ft_itoa(mshell.last_exit), false);
		prompt(&mshell);
		cmd = get_cmd(&mshell);
		run_cmd(&mshell, cmd);
	}
}
