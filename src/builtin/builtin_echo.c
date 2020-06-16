/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:47:25 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/04/28 16:40:27 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	The echo function built into the shell. Should function the same as in
**	bash, except it only has to handle the '-n' flag.
**
**	@param {t_mshell *} mshell - not used
**	@param {t_cmd} cmd
**
**	@return {bool}
*/

bool	builtin_echo(t_mshell *mshell, t_cmd cmd)
{
	bool		has_n;
	t_string	str;

	(void)mshell;
	has_n = cmd.argc > 1 && !ft_strcmp(cmd.argv[1].str, "-n");
	if (cmd.argc == 1 || (cmd.argc == 2 && has_n))
	{
		if (!has_n)
			ft_putchar_fd('\n', 1);
		return (false);
	}
	if (string_join(&cmd.argv[has_n + 1], cmd.argc - has_n - 1, " ", &str))
		error(E_ALLOC "'builtin_echo'", mshell);
	ft_putstr_fd(str.str, 1);
	string_free(&str);
	if (!has_n)
		ft_putchar_fd('\n', 1);
	return (false);
}
