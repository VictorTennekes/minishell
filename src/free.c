/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/27 10:50:22 by aaugusti       #+#   #+#                 */
/*   Updated: 2020/04/27 11:02:05 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Free all of the resources.
**
**	@param {t_mshell *} mshell
*/

void	ms_free(t_mshell *mshell)
{
	lst_foreach(mshell->env, &free);
	lst_foreach(mshell->path, &free);
}
