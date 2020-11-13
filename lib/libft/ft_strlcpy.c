/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:29 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:29 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Copy at most n - 1 bytes from src to dst. Always null-terminates the string.
**	Returns the strlen of src.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (src == NULL)
		return (0);
	if (n > 0)
	{
		i = 0;
		while (i < n - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		while (src[i])
			i++;
	}
	else
		return (ft_strlen(src));
	return (i);
}
