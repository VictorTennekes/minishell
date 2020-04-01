/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:14:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 22:49:44 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

int	main(void)
{
	t_mshell	mshell;
	t_string	cmd;

	init(&mshell);
	while (1)
	{
		prompt(&mshell);
		cmd = get_cmd();
		run_cmd(&mshell, &cmd);
		string_free(&cmd);
	}
}
