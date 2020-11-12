/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:26:37 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 13:42:00 by aaugusti      ########   odam.nl         */
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
	ft_dprintf(2, "\e[1;34m%s\e[0m \e[1;32m>\e[0m ",
		env_get(mshell, "PWD")->value.str);
}
