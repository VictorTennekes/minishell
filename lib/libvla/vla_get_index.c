/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_get_index.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Get the index of an element in the vla from it's address.
**
**	@param {t_vla} vla
**	@param {void *} elem
**	@param {bool *} result - false if failed
**
**	@return {void *} - NULL if failed
*/

size_t	vla_get_index(t_vla vla, void *elem, bool *result)
{
	size_t	index;

	if (elem < vla.vla)
	{
		if (result)
			*result = false;
		return (0);
	}
	index = (elem - vla.vla) / vla.elem_sz;
	if (index >= vla.size)
	{
		if (result)
			*result = false;
		return (0);
	}
	if (result)
		*result = true;
	return (index);
}
