/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_resize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:30 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:31 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"
#include <stdlib.h>

#ifndef FAST

static bool	check_vla(t_vla *vla)
{
	if (vla->cap == vla->size)
		return (false);
	return (true);
}

#else

static bool	check_vla(t_vla *vla)
{
	(void)vla;
	return (false);
}

#endif

/*
**	Resizes the vla to make room for more elements. This will multiply the
**	current capacity by 2.
**
**	@parma {t_vla *} vla
**
**	@return {bool} - true if the allocation failed.
*/

bool		vla_resize(t_vla *vla)
{
	void	*old;

	if (check_vla(vla))
		return (false);
	old = vla->vla;
	vla->cap *= 2;
	vla->vla = malloc(vla->elem_sz * vla->cap);
	if (!vla->vla)
	{
		vla->vla = old;
		return (true);
	}
	vla_memcpy(vla->vla, old, vla->size * vla->elem_sz);
	free(old);
	return (false);
}
