/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:16:57 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/04/28 16:17:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Reads one command from stdin. Returns the allocated string with the command.
**
**	@param {t_mshell *} mshell - Used for the errors
**
**	@return {char *}
*/

static bool	cmd_exit(t_mshell *mshell)
{
	uint8_t	exit_status;

	exit_status = mshell->last_exit;
	ft_printf("\nexit\n");
	ms_free(mshell);
	exit(exit_status);
	return (false);
}

char	*get_cmd(t_mshell *mshell)
{
	char		*res;
	int			ret;

	ret = get_next_line(0, &res);
	if (ret < 0)
	{
		free(res);
		error(E_GNL "'get_cmd'", mshell);
	}
	else if (ret == 0)
		cmd_exit(mshell);
	return (res);
}
