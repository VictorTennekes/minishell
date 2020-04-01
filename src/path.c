/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:15:16 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/01 21:37:59 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libft.h>
#include <minishell.h>
#include <sys/stat.h>

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
**	Searches for an executable file in all of the defined path directories.
**	Will return the first valid file, in order of the path variables.
**
**	@param {t_mshell *} mshell
**	@param {char *} name - name of the file, e.g. "bash"
**
**	@return {char *} - either an allocated string, or NULL if no executable
**		file is found.
*/

char	*path_find_file(t_mshell *mshell, char *name)
{
	char		*cur_path;
	struct stat	statbuf;
	t_list		*cur;
	t_string	cur_file;

	cur = mshell->path;
	while (cur)
	{
		cur_path = cur->content;
		if (string_from(cur_path, &cur_file) || string_pushc(&cur_file, '/')
				|| string_push(&cur_file, name))
			error(E_ALLOC "'path_find_file'");
		if (stat(cur_file.str, &statbuf) == 0)
			return (cur_file.str);
		string_free(&cur_file);
		cur = cur->next;
	}
	return (NULL);
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
