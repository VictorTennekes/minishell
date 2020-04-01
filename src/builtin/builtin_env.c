/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:00:32 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 22:11:57 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bssert.h>
#include <env.h>
#include <libftprintf.h>
#include <minishell.h>

/*
**	Prints out every set environment variable.
**
**	@param {t_mshell *} mshell
**	@param {uint32_t} argc
**	@param {t_string []} argv - not used
**
**	@return {bool} - true if there is an error
*/

bool	builtin_env(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	t_env		*env;
	t_list		*cur;
	t_string	buf;

	(void)argv;
	if (argc != 1)
		//TODO: set error message
		return (true);
	cur = mshell->env;
	bssert(cur);
	if (string_init(ENV_PRINT_INIT_CAP, NULL, &buf))
		error(E_ALLOC "'builtin_env'");
	while (cur)
	{
		env = cur->content;
		if (string_push(&buf, env->name.str) || string_pushc(&buf, '=') ||
				string_push(&buf, env->value.str) || string_pushc(&buf, '\n'))
			error(E_ALLOC "'builtin_env'");
		cur = cur->next;
	}
	ft_printf("%s", buf.str);
	string_free(&buf);
	return (false);
}