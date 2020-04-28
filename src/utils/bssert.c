/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bssert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 19:20:43 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/31 19:24:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdlib.h>

#ifdef DEBUG

void	bssert(void *val)
{
	if (val)
		return ;
	ft_printf("bssert failed\n");
	exit(1);
}

#else

void	bssert(void *val)
{
	(void)val;
	return ;
}

#endif
