/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:23:39 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:26:39 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Check if the name of an environment variable is valid.
**
**	@param {char *} name
**
**	@return {int32_t} - The position of the error, or -1 if no error occured.
*/

#include <stdint.h>
#include <libft.h>
#include <env.h>
#include <stdlib.h>

int32_t	env_check_name(char *name)
{
	int32_t	i;

	i = 0;
	if (ft_strcmp(name, "?") == 0)
		return (-1);
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

t_env	*env_new(t_mshell *mshell, char *name, char *value,
		bool read_only)
{
	t_env	*new;

	new = zalloc(sizeof(t_env));
	if (!new ||
			string_from(name, &new->name) || string_from(value, &new->value))
		error(E_ALLOC "'env_new'", mshell);
	new->read_only = read_only;
	if (lst_new_back(&mshell->env, new) == NULL)
		error(E_ALLOC "'env_new'", mshell);
	return (new);
}

/*
**	Used to free an envirnoment variable.
**
**	@param {t_env *} env
*/

void	env_free(t_env *env)
{
	string_free(&env->name);
	string_free(&env->value);
	free(env);
}
