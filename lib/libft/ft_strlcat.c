/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:28 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:28 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Concatenate 'src' with 'dst'. The total length of 'dst' will be at most
**	'dstsize' (including the null-byte). 'dst' will be always be null-
**	terminated. The length of the string it tried to create will be returned.
**
**	n_app: the amount of chars to append to dst (including the null-byte)
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n_app;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	n_app = (dstsize > dst_len ? dstsize - dst_len : 0);
	n_app = n_app > src_len + 1 ? src_len + 1 : n_app;
	dst_len = dst_len > dstsize ? dstsize : dst_len;
	dst += dst_len;
	if (n_app)
	{
		ft_memcpy(dst, src, n_app - 1);
		dst[n_app - 1] = '\0';
	}
	return (dst_len + src_len);
}
