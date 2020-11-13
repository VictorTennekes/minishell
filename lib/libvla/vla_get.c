/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_get.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:24 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Get a value from a vla.
**
**	@param {t_vla} vla
**	@param {size_t} index
**	@param {void *} result
**
**	@return {bool} - true if the get failed
*/

bool		vla_get(t_vla vla, size_t index, void *result)
{
	if (index >= vla.size)
		return (true);
	vla_memcpy(result, vla.vla + vla.elem_sz * index, vla.elem_sz);
	return (false);
}
