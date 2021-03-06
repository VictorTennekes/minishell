/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 20:15:16 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:05:39 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
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
		error(E_ALLOC "'init_path'", mshell);
	cur = mshell->path;
	while (cur)
	{
		if (string_push(&path, ((char *)cur->content)))
			error(E_ALLOC "'init_path'", mshell);
		if (cur->next && string_pushc(&path, ':'))
			error(E_ALLOC "'init_path'", mshell);
		cur = cur->next;
	}
	env_set(mshell, "PATH", path.str, false);
	string_free(&path);
}

/*
**	Checks wheter a file is valid.
**
**	@param {char *} filename - absolue path to the file
**	@param {bool} executable - true if the files must be executable
**
**	@return {bool} - true if valid
*/

static bool	path_check_file(char *filename, bool executable)
{
	struct stat	statbuf;

	if (stat(filename, &statbuf) != 0)
		return (false);
	if ((statbuf.st_mode & S_IFMT) != S_IFREG)
		return (false);
	if (!executable)
		return (true);
	if (!(statbuf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		return (false);
	return (true);
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

char		*path_find_file(t_mshell *mshell, char *name, bool executable)
{
	char		*cur_path;
	t_list		*cur;
	t_string	cur_file;

	cur = mshell->path;
	while (cur)
	{
		cur_path = cur->content;
		if (string_from(cur_path, &cur_file) || string_pushc(&cur_file, '/')
				|| string_push(&cur_file, name))
			error(E_ALLOC "'path_find_file'", mshell);
		if (path_check_file(cur_file.str, executable))
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

char		*path_new(t_mshell *mshell, char *value, bool update_env)
{
	char	*new;

	new = ft_strdup(value);
	if (!new || lst_new_back(&mshell->path, new) == NULL)
		error(E_ALLOC "'path_new'", mshell);
	if (update_env)
		path_update_env(mshell);
	return (new);
}

/*
**	Update the path variable based on the current value of the "PATH"
**	envirnoment variable.
**
**	@param {t_mshell *} mshell
*/

void		path_update_from_env(t_mshell *mshell)
{
	size_t		i;
	size_t		splitted_len;
	t_env		*path_env;
	t_string	*splitted;

	lst_destroy(mshell->path, free);
	mshell->path = NULL;
	path_env = env_get(mshell, "PATH");
	if (!path_env)
		error("tried to update path from env, but PATH is not set", mshell);
	if (string_split(path_env->value.str, ":", &splitted, &splitted_len))
		error(E_ALLOC "'path_update_from_env'", mshell);
	i = 0;
	while (i < splitted_len)
	{
		path_new(mshell, splitted[i].str, false);
		string_free(&splitted[i]);
		i++;
	}
	free(splitted);
}
