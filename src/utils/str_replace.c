/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_replace.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/24 16:09:52 by aaugusti  #+#   #+#                      */
/*   Updated: 2020/04/28 10:11:42 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Calculate the length of the new string. Returns -1 if no to_find occurences
**	are found in the string.
**
**	@param {char *} str
**	@param {char *} to_find
**	@param {char *} replace
**	@param {uint32_t} to_find_len
**
**	@return {int32_t}
*/

static int32_t	str_replace_len(char *str, char *to_find, uint32_t replace_len,
		int32_t to_find_len)
{
	int32_t		res;
	uint32_t	i;

	res = 0;
	i = 0;
	while(str[i])
	{
		if (!ft_strncmp(&str[i], to_find, to_find_len))
		{
			i += to_find_len;
			res++;
		}
		else
			i++;
	}
	if (res == 0)
		return (-1);
	return (i - res * to_find_len + res * replace_len);
}

/*
**	Search a string for a substring and replace it. This returns a newly
**	allocated string. Returns NULL if the allocation fails, or if
**	str = NULL, or if 'to_find' is an empty string.
**
**	@param {char *} str - must be malloced
**	@param {char *} to_find -  the string to replace
**	@param {char *} replace
**	@param {bool} do_free - true if str should be free'd
**
**	@return {char *} new
*/

char	*str_replace(char *str, char *to_find, char *replace, bool do_free)
{
	char		*res;
	int32_t		new_len;
	uint32_t	i;
	uint32_t	j;
	uint32_t	replace_len;
	uint32_t	to_find_len;

	if (!str || !*to_find)
		return (NULL);
	to_find_len = ft_strlen(to_find);
	replace_len = ft_strlen(replace);
	new_len = str_replace_len(str, to_find, replace_len, to_find_len);
	res = malloc(new_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], to_find, to_find_len))
		{
			ft_memcpy(&res[j], replace, replace_len);
			j += replace_len;
			i += to_find_len;
			continue;
		}
		res[j] = str[i];
		i++;
		j++;
	}
	res[new_len] = 0;
	if (do_free)
		free(str);
	return (res);
}
