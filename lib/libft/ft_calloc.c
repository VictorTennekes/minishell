/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:15:24 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:15:24 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	The calloc() function contiguously allocates enough space for count objects
**	that are size bytes of memory each and returns a pointer to the allocated
**	memory.  The allocated memory is filled with bytes of value zero.
**	Returns NULL if the memory allocation failed.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	tot_size;

	tot_size = count * size;
	res = malloc(tot_size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, tot_size);
	return (res);
}
