/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:26:06 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 22:51:28 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>

static bool	builtin_cd_home(t_mshell *mshell, t_string arg, t_string *path)
{
	t_env		*home;

	(void)arg;
	home = env_get(mshell, "HOME");
	if (!home)
		//TODO: set error message
		return (true);
	if (string_from(home->value.str, path))
		error(E_ALLOC "'builtin_cd_home'");
	return (false);
}

static bool	builtin_cd_other(t_mshell *mshell, t_string arg, t_string *path)
{
	if (arg.str[0] != '/')
	{
		if (string_from(env_get(mshell, "PWD")->value.str, path))
			error(E_ALLOC "'builtin_cd'");
		if (path->str[path->len - 1] != '/')
			if (string_pushc(path, '/'))
				error(E_ALLOC "'builtin_cd'");
		if (string_push(path, arg.str))
				error(E_ALLOC "'builtin_cd'");
	}
	else
		if (string_from(arg.str, path))
			error(E_ALLOC "'builtin_cd'");
	return (false);
}

/*
**	Changes the current working directory.
**
**	@param {t_mshell *} mshell
**	@param {uint32_t} argc
**	@param {t_string []} argv
**
**	@return {bool} - true if there is an error
*/

bool	builtin_cd(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	char		*cwd;
	int			chdir_ret;
	t_string	path;

	if (argc > 2)
		//TODO: set error message
		return (1);
	if ((argc == 1 ? builtin_cd_home : builtin_cd_other)
			(mshell, argv[1], &path))
		return (true);
	chdir_ret = chdir(path.str);
	string_free(&path);
	if (chdir_ret != 0)
		//TODO: set error message
		return (1);
	cwd = get_cwd();
	env_set(mshell, "PWD", cwd, false);
	free(cwd);
	return (0);
}
