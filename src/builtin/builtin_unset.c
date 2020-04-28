/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 16:13:56 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/06 12:08:03 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <minishell.h>

/*
**	Remove an environment variable from the list.
**
**	@param {t_mshell *} mshell
**	@param {uint32_t} argc
**	@param {t_string[]} argv - not used
*/

bool	builtin_unset(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	uint32_t	i;

	if (argc < 2)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (env_unset(mshell, argv[i].str, true))
		{
			ms_set_procname_err(mshell, "unset", argv[i].str);
			mshell->ms_errno = ENO_USET;
			ms_perror(mshell);
		}
		i++;
	}
	return (false);
}
