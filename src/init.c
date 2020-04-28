/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 17:12:22 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 09:27:53 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libft.h>
#include <minishell.h>
#include <path.h>
#include <stdlib.h>

/*
**	Initialize the environment variable linked list. To initialize the list,
**	we need to add an environment variable to the list. We choose PWD for this.
**
**	@param {t_mshell *} mshell
*/

static void	init_env(t_mshell *mshell)
{
	char	*cwd;
	t_env	*env;

	env = malloc(sizeof(t_env));
	cwd = get_cwd(mshell);
	if (!env ||
			string_from("PWD", &env->name) || string_from(cwd, &env->value))
		error(E_ALLOC "'init_env'", mshell);
	free(cwd);
	env->read_only = true;
	if (lst_new_back(&mshell->env, env) == NULL)
		error(E_ALLOC "'init_env'", mshell);
	env_set(mshell, "OLDPWD", env->value.str, false);
}

char	*g_path_init[] = {
	"/bin",
	"/usr/bin",
	NULL,
};

/*
**	Initialize the path variable.
**
**	@param {t_mshell *} mshell
*/

static void	init_path(t_mshell *mshell)
{
	uint32_t	i;

	i = 0;
	while (g_path_init[i])
	{
		path_new(mshell, g_path_init[i], g_path_init[i + 1] == NULL);
		i++;
	}
}

void		init(t_mshell *mshell)
{
	ft_bzero(mshell, sizeof(t_mshell));
	init_env(mshell);
	init_path(mshell);
}
