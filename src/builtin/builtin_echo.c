/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:47:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/27 11:02:47 by aaugusti      ########   odam.nl         */
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
**	@param {uint32_t} argc
**	@param {t_string []} argv
*/

bool	builtin_echo(t_mshell *mshell, uint32_t argc, t_string argv[])
{
	bool		has_n;
	t_string	str;

	(void)mshell;
	has_n = argc > 1 && !ft_strcmp(argv[1].str, "-n");
	if (argc == 1 || (argc == 2 && has_n))
	{
		if (!has_n)
			ft_putchar_fd('\n', 1);
		return (false);
	}
	if (string_join(&argv[has_n + 1], argc - has_n - 1, " ", &str))
		error(E_ALLOC "'builtin_echo'", mshell);
	ft_putstr_fd(str.str, 1);
	string_free(&str);
	if (!has_n)
		ft_putchar_fd('\n', 1);
	return (false);
}
