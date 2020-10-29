/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 18:22:43 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:27:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libft.h>
#include <libftprintf.h>
#include <path.h>
#include <stdlib.h>

/*
**	Find an environment variable with the given name.
**
**	@param {t_mshell *} mshell
**	@param {char *} name
**
**	@return {t_env *} - NULL if no match is found
*/

t_env	*env_get(t_mshell *mshell, char *name)
{
	t_list	*cur;

	cur = mshell->env;
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

bool	env_set(t_mshell *mshell, char *name, char *value,
		bool read_only)
{
	t_env	*env;

	if (env_check_name(name) != -1)
	{
		mshell->ms_errno = ENO_INVID;
		return (true);
	}
	env = env_get(mshell, name);
	if (!env)
		env_new(mshell, name, value, read_only);
	else
	{
		string_reset(&env->value, false);
		if (string_push(&env->value, value) || string_shrink(&env->value))
			error(E_ALLOC "'env_set'", mshell);
	}
	if (!ft_strcmp(name, "PATH"))
		path_update_from_env(mshell);
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

bool	env_unset(t_mshell *mshell, char *name, bool enforce_ro)
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

/*
**	Convert the envirnoment variables to a string array which can be passed to
**	a child process. The resulting array will contain string of the format
**	`key=value`. If an allocation fails, an error will be thrown.
**
**	@param {t_mshell *} mshell
**
**	@return {char *[]}
*/

char	**env_to_envp(t_mshell *mshell)
{
	char	**res;
	size_t	i;
	t_env	*cur_env;
	t_list	*cur;

	res = ft_xalloc(sizeof(char *) * (lst_size(mshell->env) + 1));
	if (!res)
		error(E_ALLOC "'env_to_envp'", mshell);
	cur = mshell->env;
	i = 0;
	while (cur)
	{
		cur_env = cur->content;
		res[i] = malloc(sizeof(char) * (cur_env->name.len +
					cur_env->value.len + 2));
		if (!res[i])
		{
			free_str_arr(res);
			error(E_ALLOC "'env_to_envp'", mshell);
		}
		ft_sprintf(res[i], "%s=%s", cur_env->name.str, cur_env->value.str);
		cur = cur->next;
		i++;
	}
	return (res);
}
