/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:43:29 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:57:37 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Exit the shell.
**
**	@param {uint32_t} argc
**	@param {t_string []} argv
*/

bool	builtin_exit(uint32_t argc, t_string argv[])
{
	int		tmp;
	uint8_t	exit_status;

	if (argc > 2)
	{
		//TODO: set error message
		return (true);
	}
	exit_status = 0; 	//TODO: should be the exit status of the last executed
						//process.
	if (argc == 2)
	{
		tmp = ft_atoi(argv[1].str);
		if (tmp >= 0 && tmp <= 255)
			exit_status = (uint8_t)tmp;
	}
	ft_printf("exit\n");
	exit(exit_status);
	return (false);
}
