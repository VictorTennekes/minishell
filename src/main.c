/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:14:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:56:47 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

int	main(void)
{
	t_string	cmd;

	while (1)
	{
		prompt();
		cmd = get_cmd();
		run_cmd(&cmd);
		string_free(&cmd);
	}
}
