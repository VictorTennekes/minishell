/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:15:16 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/01 20:54:17 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libft.h>
#include <minishell.h>

/*
**	Update the PATH env variable so it mathes the mshell->path list. This will
**	concatenate all of the path values and update the PATH variable.
**
**	@param {t_mshell *} mshell
*/

static void	path_update_env(t_mshell *mshell)
{
	t_list		*cur;
	t_string	path;

	if (string_init(0, NULL, &path))
		error(E_ALLOC "'init_path'");
	cur = mshell->path;
	while (cur)
	{
		if (string_push(&path, ((char *)cur->content)))
			error(E_ALLOC "'init_path'");
		if (cur->next && string_pushc(&path, ':'))
			error(E_ALLOC "'init_path'");
		cur = cur->next;
	}
	env_set(mshell, "PATH", path.str, false);
	string_free(&path);
}

/*
**	Add a new path variable to the list.
**
**	@param {t_mshell *} mshell
**	@param {char *} value
**	@param {bool} update_env - this should only be false if you KNOW you will
**		add more variables to path!
**
**	@return {char *} pointer to the new variable
*/

char	*path_new(t_mshell *mshell, char *value, bool update_env)
{
	char	*new;

	//TODO: check valid path?
	new = ft_strdup(value);
	if (!new || lst_new_back(&mshell->path, new) == NULL)
		error(E_ALLOC "'path_new'");
	if (update_env)
		path_update_env(mshell);
	return (new);
}
