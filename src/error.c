/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:22:28 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 13:25:58 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Outputs an error to stderr and exits the process.
**
**	@param {char *} msg
*/

void	error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
