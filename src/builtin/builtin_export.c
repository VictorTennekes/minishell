/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 17:36:49 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/06/03 20:53:04 by aaugusti      ########   odam.nl         */
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

bool		export_single(t_mshell *mshell, char *arg)
{
	bool		env_set_ret;
	char		*eq_index;
	t_string	name;
	t_string	value;

	eq_index = ft_strchr(arg, '=');
	if (!eq_index)
		return (false);
	if (string_from_range(arg, 0, eq_index - arg, &name) ||
			string_from(&eq_index[1], &value))
		error(E_ALLOC "'export_single'", mshell);
	env_set_ret = env_set(mshell, name.str, value.str, false);
	if (env_set_ret && mshell->ms_errno == ENO_INVID)
		ms_set_procname_err(mshell, "export", arg);
	string_free(&name);
	string_free(&value);
	return (env_set_ret);
}

/*
**	Set envirnoment variables from the shell.
**
**	@param {t_mshell *} mshell
**	@param {t_cmd} cmd
**
**	@return {bool}
*/

bool		builtin_export(t_mshell *mshell, t_cmd cmd)
{
	uint32_t	i;

	if (cmd.argc == 1)
	{
		print_env(mshell, "export ");
		return (false);
	}
	i = 1;
	while (i < cmd.argc)
	{
		if (export_single(mshell, cmd.argv[i].str))
		{
			mshell->last_exit = 1;
			ms_perror(mshell);
		}
		i++;
	}
	return (false);
}
