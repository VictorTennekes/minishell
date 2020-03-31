/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 21:29:48 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 21:49:09 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <env.h>
#include <libft.h>
#include <liblist.h>
#include <stdlib.h>

static void	mshell_env_free(t_list *env)
{
	t_list	*next;

	while (env)
	{
		next = env->next;
		string_free(&((t_env *)env->content)->name);
		string_free(&((t_env *)env->content)->value);
		free(env->content);
		free(env);
		env = next;
	}
}

static bool	mshell_env_init(t_mshell *mshell)
{
	t_list	*res;
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env ||
			string_from("INIT", &env->name) || string_from("init", &env->value))
		return (true);
	env->read_only = false;
	if (lst_new_back(&res, env) == NULL)
		return (true);
	mshell->env = res;
	return (false);
}

static int	mshell_env_basic(void)
{
	t_mshell	mshell;
	t_env		*env;

	assert(!mshell_env_init(&mshell));
	env = env_get(&mshell, "INIT");
	assert(env);
	assert(!ft_strcmp(env->value.str, "init"));
	assert(!env->read_only);
	assert(lst_size(mshell.env) == 1);
	assert(!env_set(&mshell, "INIT", "test", false));
	assert(!ft_strcmp(env->value.str, "test"));
	assert(!env->read_only);
	assert(lst_size(mshell.env) == 1);
	assert(!env_set(&mshell, "TEST", "abcd", true));
	env = env_get(&mshell, "TEST");
	assert(env);
	assert(!ft_strcmp(env->value.str, "abcd"));
	assert(env->read_only);
	assert(lst_size(mshell.env) == 2);
	assert(env_set(&mshell, "TEST", "is_read_only", false));
	mshell_env_free(mshell.env);
	return (0);
}

int			mshell_env(char *filename)
{
	(void)filename;
	mshell_env_basic();
	ft_putstr_fd("Success!\n", 1);
	return (0);
}
