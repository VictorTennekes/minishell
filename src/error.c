/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:22:28 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/27 11:06:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Outputs an error to stderr and exits the process.
**
**	@param {char *} msg
**	@param {t_mshell *} mshell
*/

void	error(char *msg, t_mshell *mshell)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	ms_free(mshell);
	exit(1);
}
