/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvla.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:18:35 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:18:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVLA_H
# define LIBVLA_H

# include <stddef.h>
# include <stdbool.h>

typedef struct	s_vla {
	size_t	elem_sz;
	size_t	size;
	size_t	cap;
	void	*vla;
}				t_vla;

bool			vla_get(t_vla vla, size_t index, void *result);
bool			vla_get_addr(t_vla vla, size_t index, void **result);
size_t			vla_get_index(t_vla vla, void *elem, bool *result);
bool			vla_init(size_t elem_sz, size_t init_cap, t_vla *result);
void			*vla_memcpy(void *dst, const void *src, size_t n);
bool			vla_push(t_vla *vla, void *elem, void **result);
bool			vla_resize(t_vla *vla);
bool			vla_set(t_vla vla, size_t index, void *new_value);
bool			vla_shrink(t_vla *vla);

#endif
