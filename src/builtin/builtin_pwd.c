/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_pwd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 19:16:29 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 16:39:28 by aaugusti      ########   odam.nl         */
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
**	@param {t_cmd} cmd
**
**	@return {bool}
*/

bool	builtin_pwd(t_mshell *mshell, t_cmd cmd)
{
	t_env	*pwd_env;

	(void)cmd;
	pwd_env = env_get(mshell, "PWD");
	bssert(pwd_env);
	ft_printf("%s\n", pwd_env->value.str);
	return (false);
}
