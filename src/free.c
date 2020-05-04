/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/27 10:50:22 by aaugusti       #+#   #+#                 */
/*   Updated: 2020/05/04 15:02:12 by aaugusti      ########   odam.nl         */
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
	lst_destroy(mshell->env, (void (*)(void *))&env_free);
	lst_destroy(mshell->path, &free);
}
