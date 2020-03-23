/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:14:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 13:31:24 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

int	main(void)
{
	while (1)
	{
		char	*cmd;

		prompt();
		cmd = get_cmd();
		run_cmd(cmd);
		free(cmd);
	}
}
