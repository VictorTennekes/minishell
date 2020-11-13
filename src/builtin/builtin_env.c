/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:29:15 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/13 14:49:41 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libftprintf.h>
#include <minishell.h>
#include <libft.h>

void	print_env(t_mshell *mshell, char *prefix)
{
	t_env		*env;
	t_list		*cur;
	t_string	buf;

	cur = mshell->env;
	if (string_init(ENV_PRINT_INIT_CAP, NULL, &buf))
		error(E_ALLOC "'builtin_env'", mshell);
	while (cur)
	{
		env = cur->content;
		if (ft_strcmp(env->name.str, "?") != 0)
		{
			if (prefix && string_push(&buf, prefix))
				error(E_ALLOC "'builtin_env'", mshell);
			if (string_push(&buf, env->name.str) || string_pushc(&buf, '=') ||
					string_push(&buf, env->value.str) || string_pushc(&buf, '\n'))
				error(E_ALLOC "'builtin_env'", mshell);
		}
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
