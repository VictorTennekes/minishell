/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perror.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 16:49:01 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 09:25:07 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>
#include <string.h>

char				*g_ermsgs[] = {
	[ENO_INVID] = "not a valid identifier",
	[ENO_INVCMD] = "command not found",
	[ENO_TMA] = "too many arguments",
	[ENO_HOME] = "HOME not set",
	[ENO_OLDPWD] = "OLDPWD not set",
	[ENO_USET] = "cannot unset: readonly variable",
};

static t_string	ms_strerror(t_mshell *mshell)
{
	t_string	res;

	if (string_from(g_ermsgs[mshell->ms_errno], &res))
		error(E_ALLOC "'ms_strerror'", mshell);
	return (res);
}

void			ms_set_procname(t_mshell *mshell, char *procname)
{
	if (string_from(procname, &mshell->ms_err_procname) ||
			string_shrink(&mshell->ms_err_procname))
		error(E_ALLOC "'ms_set_procname'", mshell);
}

void			ms_set_procname_err(t_mshell *mshell, char *procname,
		char *err)
{
	if (string_from(procname, &mshell->ms_err_procname) ||
			string_push(&mshell->ms_err_procname, ": `") ||
			string_push(&mshell->ms_err_procname, err) ||
			string_pushc(&mshell->ms_err_procname, '\'') ||
			string_shrink(&mshell->ms_err_procname))
		error(E_ALLOC "'ms_set_procname'", mshell);
}

bool			ms_set_error(t_mshell *mshell, t_errno ms_errno,
		char *procname)
{
	ms_set_procname(mshell, procname);
	mshell->ms_errno = ms_errno;
	return (true);
}

bool			ms_set_error_from_no(t_mshell *mshell, char *procname,
		char *err)
{
	ms_set_procname_err(mshell, procname, err);
	mshell->ms_stderrno = true;
	return (true);
}

void			ms_perror(t_mshell *mshell)
{
	char	*errstr;

	//TODO: stderr
	if (mshell->ms_stderrno)
		errstr = strerror(errno);
	else
		errstr = ms_strerror(mshell).str;
	if (mshell->ms_err_procname.len > 0)
	{
		ft_printf("%s: %s: %s\n", SHELL, mshell->ms_err_procname.str, errstr);
		string_free(&mshell->ms_err_procname);
	}
	else
		ft_printf("%s: %s\n", SHELL, errstr);
	if (!mshell->ms_stderrno)
		free(errstr);
	else
		mshell->ms_stderrno = false;
}
