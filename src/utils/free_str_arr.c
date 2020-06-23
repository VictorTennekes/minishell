/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_str_arr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 16:12:46 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/23 16:12:46 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    **free_str_arr(char **str)
{
    size_t    i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    return (NULL);
}