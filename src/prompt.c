/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:26:37 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/03/31 22:49:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <minishell.h>
#include <env.h>

/*
**	Prints the prompt to stdout.
*/

void	prompt(t_mshell *mshell)
{
	ft_printf("%s > ", env_get(mshell, "PWD")->value.str);
}
