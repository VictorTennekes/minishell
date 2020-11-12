/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perror.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 16:49:01 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 16:43:24 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char				*g_ermsgs[] = {
	[ENO_INVID] = "not a valid identifier",
	[ENO_INVCMD] = "command not found",
	[ENO_TMA] = "too many arguments",
	[ENO_HOME] = "HOME not set",
	[ENO_OLDPWD] = "OLDPWD not set",
	[ENO_USET] = "cannot unset: readonly variable",
	[ENO_UNEXTOK] = "unexpected token",
	[ENO_UNEXEOF] = "unexpected end of file",
	[ENO_NOFILE] = "No such file or directory",
	[ENO_DEFAULT] = "Error",
};

static t_string	ms_strerror(t_mshell *mshell)
{
	t_string	res;
	char		*msg;

	msg = g_ermsgs[mshell->ms_errno];
	if (string_from(msg, &res))
		error(E_ALLOC "'ms_strerror'", mshell);
	return (res);
}

void			ms_perror(t_mshell *mshell)
{
	char	*errstr;

	if (mshell->ms_stderrno)
		errstr = strerror(errno);
	else
		errstr = ms_strerror(mshell).str;
	if (mshell->ms_err_procname.len > 0)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", SHELL, mshell->ms_err_procname.str, errstr);
		string_free(&mshell->ms_err_procname);
	}
	else
		ft_dprintf(STDERR_FILENO, "%s: %s\n", SHELL, errstr);
	if (!mshell->ms_stderrno)
		free(errstr);
	else
		mshell->ms_stderrno = false;
}
