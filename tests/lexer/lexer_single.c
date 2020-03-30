/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:33:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 19:58:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <libftprintf.h>
#include <minishell.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
**	Converts the output of a bash command to a string.
**
**	@param {FILE *f}
**
**	@return {char *}
*/

static char	*mshell_lexer_single_bash_out(FILE *f)
{
	char	*buf;

	buf = malloc(500);
	if (!buf)
		return (NULL);
	fgets(buf, 500, f);
	pclose(f);
	return (buf);
}

/*
**	Concatenate the output of the lex command so it can be compared against
**	the bash output. Concatenates all the words with a space inbetween.
**
**	@param {uint32_t} word_count
**	@param {char *[]} words
*/

static char	*mshell_lexer_single_cat(uint32_t word_count, char *words[])
{
	char		*res;
	size_t		len;
	uint32_t	i;
	uint32_t	j;
	uint32_t	word_len;

	i = 0;
	len = 0;
	while(i < word_count)
	{
		len += ft_strlen(words[i]) + (i + 1 < word_count);
		i++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		word_len = ft_strlen(words[i]);
		ft_memcpy(&res[j], words[i], word_len);
		j += word_len;
		res[j] = (i + 1 < word_count) ? ' ' : '\0';
		j++;
		i++;
	}
	return (res);
}

/*
**	Compares the two outputs.
**
**	@param {uint32_t} word_count
**	@param {char *[]} words
**	@param {FILE *} bash_file
*/

static int	mshell_lexer_single_test_res(uint32_t word_count, char *words[],
		FILE *bash_file)
{
	char		*bash_out;
	char		*lex_out;

	lex_out = NULL;
	bash_out = str_replace(mshell_lexer_single_bash_out(bash_file), "\n", "",
			true);
	if (!bash_out)
		return (ft_printf("bash_out is NULL"));
	lex_out = mshell_lexer_single_cat(word_count, words);
	if (!lex_out)
		return (ft_printf("lex_out is NULL"));
	if (ft_strcmp(bash_out, lex_out))
		return (ft_printf("\n\tBash:\t[%s]\n\tLex:\t[%s]", bash_out, lex_out));
	return (0);
}

/*
**	Free the allocated output from the lex command.
**
**	@param {uint32_t} argc
**	@param {char *[]} argv
*/

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
**	Escape certain characters from the command line.
**
**	@param {char *} line - will be free'd
**
**	@return {char *}
*/

static char	*mshell_lexer_single_replace(char *line)
{
	line = str_replace(line, "\\", "\\\\", true);
	return (str_replace(line, "\"", "\\\"", true));
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

	ft_printf("testing [%s]:\n\t", line);
	argv = lex(line, &argc);
	if (argv == NULL)
		return (ft_printf("lex returned NULL"));
	line = mshell_lexer_single_replace(line);
	sprintf(bash_cmd, "echo \"echo %s\" | /bin/bash 2>&1", line);
	bash_file = popen(bash_cmd, "r");
	if (!bash_file)
		return (ft_printf("failed to execute bash command"));
	ret = mshell_lexer_single_test_res(argc - 1, &argv[1], bash_file);
	mshell_lexer_single_free(argc, argv);
	ft_printf("%s\n\n", !ret ? "passed!" : "");
	return (ret);
}
