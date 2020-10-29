/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_str_arr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:14:44 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:14:44 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**free_str_arr(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
