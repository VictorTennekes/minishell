/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_char_arr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 15:23:38 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/22 15:23:38 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    **free_char_arr(char **str)
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