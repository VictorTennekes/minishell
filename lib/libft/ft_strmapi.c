/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:33 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:33 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

/*
**	Create a new string based on 's'. Every char in 's' is passed through the
**	function 'f' and the return-value is used to build the new string. Al-
**	ways null-terminates the result string. Returns NULL if the allocation fails
**	or when 's' or 'f' are null.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	s_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	res = (char*)malloc(s_len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
