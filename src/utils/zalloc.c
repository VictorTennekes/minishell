/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:31:06 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 18:33:04 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Allocate a block of data and initialize it to be all 0.
**
**	@param {size_t} size
**
**	@return {void *} - NULL if malloc failed
*/

void	*zalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
