/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 16:13:56 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 16:42:01 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <minishell.h>

/*
**	Remove an environment variable from the list.
**
**	@param {t_mshell *} mshell
**	@param {t_cmd} cmd
**
**	@return {bool}
*/

bool	builtin_unset(t_mshell *mshell, t_cmd cmd)
{
	uint32_t	i;

	if (cmd.argc < 2)
		return (false);
	i = 1;
	while (i < cmd.argc)
	{
		if (env_unset(mshell, cmd.argv[i].str, true))
		{
			ms_set_procname_err(mshell, "unset", cmd.argv[i].str);
			mshell->ms_errno = ENO_USET;
			ms_perror(mshell);
		}
		i++;
	}
	return (false);
}
