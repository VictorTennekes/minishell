/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 19:04:58 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/01 21:19:29 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>

static char	*get_cwd_shrink(char *cwd)
{
	char	*res;
	size_t	real_len;

	real_len = ft_strlen(cwd);
	res = malloc(real_len + 1);
	if (!res)
		error(E_ALLOC "'get_cwd_shrink'");
	ft_memcpy(res, cwd, real_len + 1);
	free(cwd);
	return (res);
}

/*
**	Puts the current working directory in an allocated string buffer.
**
**	@return {char *}
*/

char		*get_cwd(void)
{
	char	*res;
	size_t	cur_size;

	cur_size = CWD_INIT_SIZE;
	while (42)
	{
		res = malloc(cur_size);
		if (!res)
			error(E_ALLOC "'get_cwd'");
		if (getcwd(res, cur_size))
			return (get_cwd_shrink(res));
		free(res);
		cur_size *= 2;
	}
}
