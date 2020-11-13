/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:15:23 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:15:23 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Write zeroes to a byte string.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
