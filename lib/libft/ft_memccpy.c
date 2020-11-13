/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:10 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:10 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Copies at most 'n' bytes from 'src' to 'dest' until 'c' is encountered in
**	'src'. If 'c' is encountered before 'n' is reached a pointer to the first
**	occurence of 'c' is returned. If 'n' is reached first then NULL is returned.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char *)dest) = *((unsigned char*)src);
		if (*((unsigned char *)dest) == (unsigned char)c)
			break ;
		dest++;
		src++;
		n--;
	}
	if (n)
		return (dest + 1);
	return (NULL);
}
