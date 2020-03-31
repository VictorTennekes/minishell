/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:12:22 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 21:20:18 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libft.h>
#include <minishell.h>
#include <utils.h>

static void	init_env(t_mshell *mshell, char *cwd)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env ||
			string_from("PWD", &env->name) || string_from(cwd, &env->value))
		error(E_ALLOC "'init_env'");
	env->read_only = true;
	if (lst_new_back(&mshell->env, env) == NULL)
		error(E_ALLOC "'init_env'");
}

void	init(t_mshell *mshell)
{
	char	*cwd;

	ft_bzero(mshell, sizeof(t_mshell));
	cwd = get_cwd();
	init_env(mshell, cwd);
	free(cwd);
}
