/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:36 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Find the last occurence of 'c' in 's'. If 'c' is not encountered in 's' then
**	null is returned. Otherwise a pointer in 's' to 'c' is returned.
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*res;

	res = NULL;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if (!c)
		return ((char*)s);
	return ((char*)res);
}
