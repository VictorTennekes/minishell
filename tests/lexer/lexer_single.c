/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:33:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 16:05:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIFF_ERR ("diff found for {argc = %d, bash_i = %d}")

static int	mshell_lexer_single_diff(uint32_t word_count, char *words[],
		char *bash_out)
{
	uint32_t	i;

	ft_printf("\n\tBash:\t%s\n\tLex:\t", bash_out);
	i = 0;
	while (i < word_count)
	{
		ft_printf("%s%c", words[i], (i + 1 < word_count) ? ' ' : '\n');
		i++;
	}
	return (1);
}

static int	mshell_lexer_single_test_res(uint32_t word_count, char *words[],
		FILE *bash_file)
{
	char		bash_out[500];
	uint32_t	bash_i;
	uint32_t	word_i;
	uint32_t	word_len;

	fscanf(bash_file, "%s", bash_out);
	if (ferror(bash_file))
		return (ft_printf("error while reading bash output: %s",
					strerror(errno)));
	bash_i = 0;
	word_i = 0;
	while (word_i < word_count)
	{
		word_len = ft_strlen(words[word_i]);
		if (strncmp(words[word_i], &bash_out[bash_i], word_len))
			return (mshell_lexer_single_diff(word_count, words, bash_out));
		bash_i += word_len;
		if (bash_out[bash_i] != ' ')
			return (mshell_lexer_single_diff(word_count, words, bash_out));
		bash_i++;
		word_i++;
	}
	return (0);
}

static void	mshell_lexer_single_free(uint32_t argc, char *argv[])
{
	uint32_t	i;
	
	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

/*
**	Test the lexer with a single line, agains the output of bash. Output will
**	be printed to stdout.
**
**	@param {char *} line
**
**	@return {int} - 0 on success, >0 on fail.
*/

int			mshell_lexer_single(char *line)
{
	FILE		*bash_file;
	char		**argv;
	char		bash_cmd[500];
	int			ret;
	uint32_t	argc;

	ft_printf("testing [%s]: ", line);
	argv = lex(line, &argc);
	if (argv == NULL)
		return (ft_printf("lex returned NULL"));
	sprintf(bash_cmd, "echo \"echo \"%s\"\" | /bin/bash", line);
	bash_file = popen(bash_cmd, "r");
	if (!bash_file)
		return (ft_printf("failed to execute bash command"));
	ret = mshell_lexer_single_test_res(argc - 1, &argv[1], bash_file);
	mshell_lexer_single_free(argc, argv);
	ft_printf("%s\n", !ret ? "passed!" : "");
	return (ret);
}
