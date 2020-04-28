/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 22:00:32 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 16:38:48 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bssert.h>
#include <env.h>
#include <libftprintf.h>
#include <minishell.h>

void	print_env(t_mshell *mshell, char *prefix)
{
	t_env		*env;
	t_list		*cur;
	t_string	buf;

	cur = mshell->env;
	bssert(cur);
	if (string_init(ENV_PRINT_INIT_CAP, NULL, &buf))
		error(E_ALLOC "'builtin_env'", mshell);
	while (cur)
	{
		env = cur->content;
		if (prefix && string_push(&buf, prefix))
			error(E_ALLOC "'builtin_env'", mshell);
		if (string_push(&buf, env->name.str) || string_pushc(&buf, '=') ||
				string_push(&buf, env->value.str) || string_pushc(&buf, '\n'))
			error(E_ALLOC "'builtin_env'", mshell);
		cur = cur->next;
	}
	ft_printf("%s", buf.str);
	string_free(&buf);
}

/*
**	Prints out every set environment variable.
**
**	@param {t_mshell *} mshell
**	@param {t_cmd} cmd
**
**	@return {bool} - true if there is an error
*/

bool	builtin_env(t_mshell *mshell, t_cmd cmd)
{
	if (cmd.argc != 1)
		return (ms_set_error(mshell, ENO_TMA, "env"));
	print_env(mshell, NULL);
	return (false);
}
