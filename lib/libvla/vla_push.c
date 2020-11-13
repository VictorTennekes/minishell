/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:30 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:30 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Pushes a value onto the end of the VLA.
**
**	@param {t_vla *} vla
**	@param {void *} elem - this element should have the size of elem_sz in the
**		t_vla struct.
**	@param {void **} result - pointer to store the new location of the element.
**		If this is NULL it will not be set.
**
**	@return {bool} - true if an allocation failed
*/

bool	vla_push(t_vla *vla, void *elem, void **result)
{
	void	*new_loc;

	if (vla->size >= vla->cap)
		if (vla_resize(vla))
			return (true);
	new_loc = vla->vla + vla->elem_sz * vla->size;
	vla_memcpy(new_loc, elem, vla->elem_sz);
	if (result)
		*result = new_loc;
	vla->size++;
	return (false);
}
