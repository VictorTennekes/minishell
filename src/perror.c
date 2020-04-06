/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:49:01 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/06 09:16:59 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libftprintf.h>

char				*g_ermsgs[] = {
	[ENO_INVID] = "not a valid identifier",
	[ENO_INVCMD] = "command not found",
};

static t_string	ms_strerror(t_errno ms_errno)
{
	t_string	res;

	if (string_from(g_ermsgs[ms_errno], &res))
		error(E_ALLOC "'ms_strerror'");
	return (res);
}

void			ms_set_procname(t_mshell *mshell, char *procname)
{
	if (string_from(procname, &mshell->ms_err_procname) ||
			string_shrink(&mshell->ms_err_procname))
		error(E_ALLOC "'ms_set_procname'");
}

void			ms_set_procname_err(t_mshell *mshell, char *procname,
		char *err)
{
	if (string_from(procname, &mshell->ms_err_procname) ||
			string_push(&mshell->ms_err_procname, ": `") ||
			string_push(&mshell->ms_err_procname, err) ||
			string_pushc(&mshell->ms_err_procname, '\'') ||
			string_shrink(&mshell->ms_err_procname))
		error(E_ALLOC "'ms_set_procname'");
}

void			ms_perror(t_mshell *mshell)
{
	//TODO: stderr
	if (mshell->ms_err_procname.len > 0)
	{
		ft_printf("%s: %s: %s\n", SHELL, mshell->ms_err_procname.str,
					ms_strerror(mshell->ms_errno).str);
		string_free(&mshell->ms_err_procname);
	}
	else
		ft_printf("%s: %s\n", SHELL, ms_strerror(mshell->ms_errno).str);
}
