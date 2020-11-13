/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_shrink.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:32 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:32 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"
#include <stdlib.h>

/*
**	Shrink the vla down to the minimal size needed to store all elements.
**
**	@param {t_vla *} vla
**
**	@return {bool} - true if the allocation failed.
*/

bool	vla_shrink(t_vla *vla)
{
	void	*old;
	size_t	new_sz;

	old = vla->vla;
	new_sz = vla->size * vla->elem_sz;
	vla->vla = malloc(new_sz);
	if (!vla->vla)
	{
		vla->vla = old;
		return (true);
	}
	vla_memcpy(vla->vla, old, new_sz);
	free(old);
	vla->cap = vla->size;
	return (false);
}
