/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perror_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:50:03 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:50:16 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
