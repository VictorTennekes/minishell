/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:31 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:31 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Set a value in a vla.
**
**	@param {t_vla} vla
**	@param {size_t} index
**	@param {void *} new_value - a pointer to the value to store in the vla
**
**	@return {bool} - true if the set failed
*/

bool	vla_set(t_vla vla, size_t index, void *new_value)
{
	if (index >= vla.size)
		return (true);
	vla_memcpy(vla.vla + vla.elem_sz * index, new_value, vla.elem_sz);
	return (false);
}
