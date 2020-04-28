/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_file.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/24 09:29:03 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 09:35:11 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <get_next_line.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdlib.h>

static int	mshell_parser_file_func(int fd, void *mshell)
{
	char		*line;
	t_string	line_str;
	int			gnl_ret;
	int			fail_count;

	fail_count = 0;
	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
		{
			ft_printf("mshell_parser_file: get_next_line returned -1\n");
			return (-1);
		}
		if (gnl_ret == 0)
		{
			free(line);
			return (fail_count);
		}
		if (*line && *line != '#')
		{
			if (string_from("echo ", &line_str) || string_push(&line_str, line))
			{
				ft_printf("mshell_parser_file: allocation failed\n");
				return (-1);
			}
			string_shrink(&line_str);
			fail_count += mshell_parser_single(mshell, &line_str);
			string_free(&line_str);
		}
		free(line);
	}
}

int			mshell_parser_file(t_mshell *mshell, char *filename)
{
	return (file_wapper_arg(filename, mshell_parser_file_func, mshell));
}
