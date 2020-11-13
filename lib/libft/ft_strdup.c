/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

/*
**	Duplicate a string. Returns NULL if the allocation fails. Result will always
**	be NULL-terminated.
*/

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*res;

	s_len = ft_strlen(s1);
	res = (char *)malloc(s_len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, s_len + 1);
	return (res);
}
