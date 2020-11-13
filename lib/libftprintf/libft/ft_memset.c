/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:23:12 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:23:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Set 'len' bytes in the buffer 'b' to 'c'. Returns 'b'.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;

	b_cpy = b;
	while (len > 0)
	{
		*b_cpy = (unsigned char)c;
		len--;
		b_cpy++;
	}
	return (b);
}
