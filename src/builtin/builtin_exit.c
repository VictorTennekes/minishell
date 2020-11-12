/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_exit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:29:22 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:29:22 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Exit the shell.
**
**	@param {t_mshell *} mshell - not used
**	@param {t_cmd} cmd
**
**	@return {bool}
*/

#include <stdio.h>

bool	builtin_exit(t_mshell *mshell, t_cmd cmd)
{
	int		tmp;
	uint8_t	exit_status;

	(void)mshell;
	exit_status = mshell->last_exit;
	if (cmd.argc == 2)
	{
		if (!ft_isdigit(cmd.argv[1].str[0]))
			tmp = 2;
		else
			tmp = ft_atoi(cmd.argv[1].str);
		exit_status = (uint8_t)tmp % 256;
	}
	else if (cmd.argc > 2)
	{
		if (!ft_isdigit(cmd.argv[1].str[0]))
			exit_status = 2;
		else
			exit_status = 1;
	}
	// ft_printf("exit\n");
	ms_free(mshell);
	exit(exit_status);
	return (false);
}
