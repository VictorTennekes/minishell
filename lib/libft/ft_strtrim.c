/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:38 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Trim all of the chars in 'set' form the start and end of 's1'. Returns a
**	newly allocated string with the result. Returns NULL if the allocation
**	failed. If there are only chars in 's1' which are also in 'set' an empty
**	string is returned. If either 's1' or 'set' is NULL, the funcion returns
**	NULL and does nothing.
*/

char		*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (!s1[start])
		return (ft_strdup(""));
	len = ft_strlen(s1) - start - 1;
	while (ft_strchr(set, s1[start + len]) && s1[start + len])
		len--;
	len++;
	return (ft_substr(s1, start, len));
}
