/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_get_addr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Get the address of an element in the VLA.
**
**	@param {t_vla} vla
**	@param {size_t} index
**	@param {void **} result
**
**	@return {bool} - true if the get failed
*/

bool	vla_get_addr(t_vla vla, size_t index, void **result)
{
	if (index >= vla.size)
		return (true);
	*result = vla.vla + vla.elem_sz * index;
	return (false);
}
