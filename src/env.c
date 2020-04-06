/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:22:43 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/06 12:07:36 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bssert.h>
#include <env.h>
#include <libft.h>
#include <stdlib.h>

/*
**	Used to free an envirnoment variable.
**
**	@param {t_env *} env
*/

static void		env_free(t_env *env)
{
	string_free(&env->name);
	string_free(&env->value);
	free(env);
}

static int32_t		env_check_name(char *name)
{
	int32_t	i;

	i = 0;
	while (name[i])
	{
		if (!((name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] >= 'A' && name[i] <= 'Z') ||
			(i != 0 && (name[i] >= '0' && name[i] <= '9')) ||
			name[i] == '_'))
			return (i);
		i++;
	}
	return (-1);
}

/*
**	Add a new environment variable. Throws an error is any allocation fails.
**
**	@param {t_mshell *} mshell
**	@param {char *} name
**	@param {char *} value
**	@param {bool} read_only
**
**	@return {t_env *} - a pointer to the new variable
*/

static t_env	*env_new(t_mshell *mshell, char *name, char *value,
		bool read_only)
{
	t_env	*new;

	new = zalloc(sizeof(t_env));
	if (!new ||
			string_from(name, &new->name) || string_from(value, &new->value))
		error(E_ALLOC "'env_new'");
	new->read_only = read_only;
	if (lst_new_back(&mshell->env, new) == NULL)
		error(E_ALLOC "'env_new'");
	return (new);
}

/*
**	Find an environment variable with the given name.
**
**	@param {t_mshell *} mshell
**	@param {char *} name
**
**	@return {t_env *} - NULL if no match is found
*/

t_env			*env_get(t_mshell *mshell, char *name)
{
	t_list	*cur;

	cur = mshell->env;
	bssert(cur);
	while (cur)
	{
		if (!ft_strcmp(name, ((t_env *)cur->content)->name.str))
			return (cur->content);
		cur = cur->next;
	}
	return (NULL);
}

/*
**	Sets an environment variable. If the variable doest not yet exist it will
**	be added to the end of the list. If the allocation fails, an error will be
**	thrown.
**
**	@param {t_mshell *} mshell
**	@param {char *} name
**	@param {char *} value
**	@param {bool} read_only - only used when creating a new variable
**
**	@return {bool} - true if an error occured. ms_errno will be set.
*/

bool			env_set(t_mshell *mshell, char *name, char *value, bool read_only)
{
	t_env	*env;

	if (env_check_name(name) != -1)
	{
		mshell->ms_errno = ENO_INVID;
		return (true);
	}
	env = env_get(mshell, name);
	if (!env)
	{
		env_new(mshell, name, value, read_only);
		return (false);
	}
	string_reset(&env->value, false);
	if (string_push(&env->value, value) || string_shrink(&env->value))
		error(E_ALLOC "'env_set'");
	return (false);
}

/*
**	Remove (or 'unset') an environment variable.
**
**	@param {t_mshell *} mshell
**	@param {char *} name - the name of the variable to unset
**	@param {bool} enforce_ro - true if the variable should only be removed if
**		it is not read_only.
**
**	@return {bool} - true if the variable be not unset because of read_only.
*/

bool			env_unset(t_mshell *mshell, char *name, bool enforce_ro)
{
	t_env	*env;
	t_list	*parent;

	env = env_get(mshell, name);
	if (!env)
		return (false);
	if (env->read_only && enforce_ro)
		return (true);
	parent = lst_find_parent(env, mshell->env);
	//assert(parent);
	lst_remove(parent, (void(*)(void *))env_free);
	return (false);
}
