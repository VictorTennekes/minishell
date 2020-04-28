/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 19:04:58 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 09:27:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>

static char	*get_cwd_shrink(t_mshell *mshell, char *cwd)
{
	char	*res;
	size_t	real_len;

	real_len = ft_strlen(cwd);
	res = malloc(real_len + 1);
	if (!res)
		error(E_ALLOC "'get_cwd_shrink'", mshell);
	ft_memcpy(res, cwd, real_len + 1);
	free(cwd);
	return (res);
}

/*
**	Puts the current working directory in an allocated string buffer.
**
**	@param {t_mshell *} mshell - Used for error
**
**	@return {char *}
*/

char		*get_cwd(t_mshell *mshell)
{
	char	*res;
	size_t	cur_size;

	cur_size = CWD_INIT_CAP;
	while (42)
	{
		res = malloc(cur_size);
		if (!res)
			error(E_ALLOC "'get_cwd'", mshell);
		if (getcwd(res, cur_size))
			return (get_cwd_shrink(mshell, res));
		free(res);
		cur_size *= 2;
	}
}
