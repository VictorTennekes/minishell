/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 13:16:57 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:06:11 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

/*
**	Reads one command from stdin. Returns the allocated string with the command.
**
**	@param {t_mshell *} mshell - Used for the errors
**
**	@return {char *}
*/

static bool	cmd_exit(t_mshell *mshell)
{
	uint8_t	exit_status;

	exit_status = mshell->last_exit;
	ft_putstr_fd("\nexit\n", 2);
	ms_free(mshell);
	exit(exit_status);
	return (false);
}

static void	handle_ctrld(t_mshell *mshell, t_string *input, char *res, int ret)
{
	if (mshell->signal == true)
	{
		string_reset(input, true);
		mshell->signal = false;
	}
	if (ret == 0 && ((res) ? ft_strlen(res) : 0) + input->len == 0)
		cmd_exit(mshell);
	if (string_push(input, res))
		error(E_ALLOC "'get cmd'", mshell);
	free(res);
}

char		*get_cmd(t_mshell *mshell)
{
	char		*res;
	t_string	input;
	int			ret;

	if (string_init(10, "", &input))
		error(E_ALLOC "'get cmd'", mshell);
	ret = get_next_line(0, &res);
	while (ret >= 0)
	{
		handle_ctrld(mshell, &input, res, ret);
		if (ret == 1)
			break ;
		ret = get_next_line(0, &res);
	}
	if (ret < 0)
	{
		free(res);
		error(E_GNL "'get_cmd'", mshell);
	}
	return (input.str);
}
