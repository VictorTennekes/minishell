/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:44:52 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:45:40 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <minishell.h>
#include <signal.h>

/*
**	Defense for using a global variable can be found in a stackoverflow
**	question id `6970224`.
*/

t_mshell	*g_mshell;

static void	signal_int(int sig)
{
	(void)sig;
	ft_printf("\n");
	g_mshell->signal = true;
	prompt(g_mshell);
}

void		init_signal(t_mshell *mshell)
{
	g_mshell = mshell;
	if (signal(SIGINT, signal_int) == SIG_ERR)
		error("signal failed", mshell);
}
