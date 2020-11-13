/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:22 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:22 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

/*
**	Copy the string to be added to the result and return the pointer to the
**	freshly allocated string. Returns NULL if allocation fails. The amount of
**	chars in the returned string is stored in to_add_len.
*/

static char		*ft_split_create_string(char const *s, char c,
		size_t *to_add_len)
{
	char	*res;
	size_t	n;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	res = (char *)malloc(n + 1);
	if (res == NULL)
		return (NULL);
	*to_add_len = n;
	res[n] = '\0';
	while (n > 0)
	{
		res[n - 1] = s[n - 1];
		n--;
	}
	return (res);
}

/*
**	Get the pointer to the allocated memory with the right size for the final
**	result. To do this, first the mount of strings in the final array are
**	counted.
*/

static char		**ft_split_get_mem(char const *s, char c)
{
	char	**res;
	char	prev;
	size_t	arr_size;

	arr_size = 0;
	if (!c && *s)
		arr_size++;
	if (c && *s)
	{
		prev = 0;
		if (*s != c)
			arr_size++;
		while (*s)
		{
			if (*s != c && prev == c)
				arr_size++;
			prev = *s;
			s++;
		}
	}
	res = (char **)malloc((arr_size + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[arr_size] = NULL;
	return (res);
}

/*
**	Skip all of the occurences of 'c' in 's'.
*/

static int		ft_split_skip_c(char **s, char c)
{
	while (**s == c)
		(*s)++;
	if (!**s)
		return (1);
	return (0);
}

/*
**	Clear the list in case of a failed allocation to prevent leaks.
*/

static char		**ft_split_remove_list(char **list, int n)
{
	while (n >= 0)
	{
		free(list[n]);
		n--;
	}
	free(list);
	return (NULL);
}

/*
**	Split the string 's' into new strings delimited by 'c'-chars. Multiple
**	occurences of c after each other will be interpreted as a single split
**	point. Returns an array of strings if everything went well. Returns NULL
**	if any allocation fails. The result is always NULL-terminated.
*/

char			**ft_split(char const *s, char c)
{
	size_t	to_add_len;
	int		i;
	char	**res;

	if (s == NULL)
		return (NULL);
	res = ft_split_get_mem(s, c);
	if (res == NULL)
		return (NULL);
	if (*s == '\0')
		return (res);
	i = 0;
	while (*s)
	{
		if (ft_split_skip_c((char **)&s, c))
			break ;
		res[i] = ft_split_create_string(s, c, &to_add_len);
		if (res[i] == NULL)
			return (ft_split_remove_list(res, i - 1));
		s += to_add_len;
		i++;
	}
	return (res);
}
