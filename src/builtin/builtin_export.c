/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:36:49 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/03 16:46:20 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <env.h>
#include <libft.h>

/*
**	Basic rules:
**		* If no '=' is found in the argument, then no action is performed
**		* Only the first '=' in the argument will be parsed as an actual assign
**			token. All of the other ones will be part of the value.
**		* If no value is given (e.g. 'ABC=') than the value will be set to an
**			empty string.
**		* Export will contine through every argument even if an invalid
**			identifier is given.
*/

static bool	export_single(t_mshell *mshell, t_string arg)
{
	t_string	name;
	t_string	value;
	char		*eq_index;
	bool		env_set_ret;

	eq_index = ft_strchr(arg.str, '=');
	if (!eq_index)
		return (false);
	if (string_from_range(arg.str, 0, eq_index - arg.str, &name) ||
			string_from(&eq_index[1], &value))
		error(E_ALLOC "'export_single'");
	env_set_ret = env_set(mshell, name.str, value.str, false);
	string_free(&name);
	string_free(&value);
	if (env_set_ret)
		//TODO: set error to invalid identifier
		return (true);
	return (false);
}

/*
**	Set envirnoment variables from the shell.
**
**	@param {t_mshell *} mshell - not used
**	@param {uint32_t} argc
**	@param {t_string []} argv
*/

bool		builtin_export(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	uint32_t	i;

	if (argc == 1)
	{
		print_env(mshell, "export ");
		return (false);
	}
	i = 1;
	while (i < argc)
	{
		//TODO: print error if true
		export_single(mshell, argv[i]);
		i++;
	}
	return (false);
}
