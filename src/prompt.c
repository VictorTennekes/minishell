/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:26:37 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/03/31 22:49:26 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <minishell.h>
#include <env.h>

/*
**	Prints the prompt to stdout.
*/

#include <stdio.h>

void	prompt(t_mshell *mshell)
{
	dprintf(2, "\e[1;34m%s\e[0m \e[1;32m>\e[0m ",
		env_get(mshell, "PWD")->value.str);
	// ft_printf("\e[1;34m%s\e[0m \e[1;32m>\e[0m ",
	// 	env_get(mshell, "PWD")->value.str);
}
