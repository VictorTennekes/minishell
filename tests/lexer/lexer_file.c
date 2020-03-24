/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:29:03 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 09:31:09 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <get_next_line.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

static int	mshell_lexer_file_func(int fd)
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
			ft_printf("mshell_lexer_file: get_next_line returned -1\n");
			return (-1);
		}
		if (gnl_ret == 0)
		{
			free(line);
			return (fail_count);
		}
		if (*line && *line != '#')
			fail_count += mshell_lexer_single(line);
		free(line);
	}
}

int			mshell_lexer_file(char *filename)
{
	return (file_wapper(filename, mshell_lexer_file_func));
}
