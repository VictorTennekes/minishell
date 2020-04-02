/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:13:56 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/02 17:33:46 by aaugusti         ###   ########.fr       */
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

	#include <libftprintf.h>

bool	builtin_unset(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	uint32_t	i;

	if (argc < 2)
		//TODO: set error message
		return (true);
	i = 1;
	while (i < argc)
	{
		if (env_unset(mshell, argv[i].str, true))
			//TODO: better error messages
			ft_printf(
				"minishell: unset: %s: cannot unset: readonly variable\n",
				argv[i].str);
		i++;
	}
	return (false);
}
