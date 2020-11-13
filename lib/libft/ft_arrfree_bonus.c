/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrfree_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:15:15 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:15:15 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Frees a string array, like the one ft_split returns.
**
**	@param {char **} arr
*/

void	ft_arrfree(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
