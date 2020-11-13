/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:35 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Finds the first occurence of the string 'neelde' in 'haystack' where no more
**	than 'len' bytes are searched. Returns a pointer in 'haystack' to the first
**	char of the occurence of 'needle'. Returns NULL if there is no occurence
**	of 'needle' found in the first 'len' bytes of 'haystack'.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	needle_len;

	if (!*needle)
		return ((char*)haystack);
	n = 0;
	needle_len = ft_strlen(needle);
	while (*haystack && n < len)
	{
		i = 0;
		while (needle[i] && (n + i < len) && (needle[i] == haystack[i]))
			i++;
		if (i == needle_len)
			return ((char*)haystack);
		haystack++;
		n++;
	}
	return (NULL);
}
