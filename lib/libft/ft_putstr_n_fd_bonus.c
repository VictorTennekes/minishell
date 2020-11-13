/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_n_fd_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:16:23 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:16:23 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

/*
**	Write at most 'n' bytes of 's' to 'fd'.
*/

void	ft_putstr_n_fd(char *s, size_t n, int fd)
{
	size_t	s_len;

	if (s == NULL)
		return ;
	s_len = ft_strlen(s);
	write(fd, s, (s_len > n) ? n : s_len);
}
