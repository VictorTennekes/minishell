/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:37:52 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 20:07:05 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

#define STR (0)
#define TO_FIND (1)
#define REPLACE (2)
#define EXPECTED (3)

static void	arrfree(char ***arr)
{
	ft_arrfree(*arr);
}

static int	mshell_str_replace_single(char *line)
{
	char	**split			__attribute__ ((__cleanup__(arrfree)));
	char	*replace_res;
	size_t	split_len;

	ft_printf("testing [%s]: ", str_replace(line, "\t", " ", true));
	split = ft_split(line, '\t');
	if (!split)
		return (ft_printf("ft_split returned NULL\n"));
	split_len = ft_arrlen(split);
	if (split_len == 3)
		replace_res = str_replace(split[STR], split[TO_FIND], "", false);
	else if (split_len == 4)
		replace_res = str_replace(split[STR], split[TO_FIND], split[REPLACE],
				false);
	else
		return (ft_printf("invalid line\n"));
	if (!replace_res)
		return (ft_strlen("str_replace returned NULL\n"));
	if (ft_strcmp(replace_res, split[EXPECTED]))
	{
		ft_printf("failed\n\tresult:\t\t%s\n\texpected:\t%s\n",
				replace_res, split[EXPECTED]);
		return (1);
	}
	ft_printf("passed\n");
	return (0);
}

static int	mshell_str_replace_test(int fd)
{
	char	*line;
	int		gnl_ret;
	int		fail_count;

	fail_count = 0;
	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
		{
			ft_printf("mshell_str_replace_test: get_next_line returned -1\n");
			return (-1);
		}
		if (gnl_ret == 0)
		{
			free(line);
			return (fail_count);
		}
		if (*line && *line != '#')
			fail_count += (mshell_str_replace_single(line) ? 1 : 0);
	}
}

int			mshell_str_replace(char *filename)
{
	if (!filename)
		return (1);
	return (file_wapper(filename, mshell_str_replace_test));
}
