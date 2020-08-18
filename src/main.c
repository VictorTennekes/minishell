/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:14:58 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/08/18 14:52:16 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

int	main(void)
{
	t_mshell	mshell;
	char		*cmd;

	init(&mshell);
	while (1)
	{
		prompt(&mshell);
		cmd = get_cmd(&mshell);
		run_cmd(&mshell, cmd);
	}
}
