/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:11 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:11 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Compare the byte strings 's1' to 's2'. No more than 'n' bytes are checked.
**	If a difference is found the difference between the bytes at which the
**	difference occured is returned. (*s1 - *s2). Both bytestrings are inter-
**	preted as unsigned char strings. If no difference in the first n bytes is
**	found, 0 is returned.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0 && *((unsigned char*)s1) == *((unsigned char*)s2))
	{
		n--;
		s1++;
		s2++;
	}
	if (!n)
		return (0);
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
