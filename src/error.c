/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:51:23 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:51:24 by aaugusti      ########   odam.nl         */
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
