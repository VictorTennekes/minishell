/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 19:16:29 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/06 10:51:57 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bssert.h>
#include <env.h>
#include <libftprintf.h>
#include <minishell.h>

/*
**	Print the current working directory.
**
**	@param {t_mshell *} mshell
**	@param {uint32_t} argc
**	@param {t_string[]} argv - not used
*/

bool	builtin_pwd(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	t_env	*pwd_env;

	(void)argc;
	(void)argv;
	pwd_env = env_get(mshell, "PWD");
	bssert(pwd_env);
	ft_printf("%s\n", pwd_env->value.str);
	return (false);
}
