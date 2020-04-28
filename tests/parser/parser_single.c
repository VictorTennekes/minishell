/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_single.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/24 09:33:25 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/27 11:31:51 by aaugusti      ########   odam.nl         */
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

static bool	mshell_parser_single_bash_out(FILE *f, t_string *res)
{
	char		buf[500];

	ft_bzero(buf, 500);
	if (string_init(500, NULL, res))
		return (true);
	fgets(buf, 500, f);
	pclose(f);
	if (string_push(res, buf))
		return (true);
	return (false);
}

/*
**	Compares the two outputs.
**
**	@param {uint32_t} word_count
**	@param {char *[]} words
**	@param {FILE *} bash_file
*/

static int	mshell_parser_single_test_res(uint32_t word_count, t_string words[],
		FILE *bash_file)
{
	t_string	bash_out;
	t_string	parse_out;
	int			res;

	if (mshell_parser_single_bash_out(bash_file, &bash_out))
		return (ft_printf("allocation failed"));
	string_replace(&bash_out, "\n", "");
	if (string_join(words, word_count, " ", &parse_out))
	{
		string_free(&bash_out);
		return (ft_printf("allocation failed"));
	}
	res = ft_strcmp(bash_out.str, parse_out.str);
	if (res)
		ft_printf("\n\tBash:\t[%s]\n\tLex:\t[%s]", bash_out.str, parse_out.str);
	string_free(&bash_out);
	string_free(&parse_out);
	return (res != 0);
}

/*
**	Free the allocated output from the parse command.
**
**	@param {uint32_t} argc
**	@param {char *[]} argv
*/

static void	mshell_parser_single_free(uint32_t argc, t_string argv[])
{
	uint32_t	i;
	
	i = 0;
	while (i < argc)
	{
		string_free(&argv[i]);
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

static void	mshell_parser_single_replace(t_string *line)
{
	string_replace(line, "\\", "\\\\");
	string_replace(line, "\"", "\\\"");
	string_shrink(line);
}

/*
**	Test the parser with a single line, agains the output of bash. Output will
**	be printed to stdout.
**
**	@param {t_mshell *} mshell - Used for errors
**	@param {char *} line
**
**	@return {int} - 0 on success, >0 on fail.
*/

int			mshell_parser_single(t_mshell *mshell, t_string *line)
{
	FILE		*bash_file;
	t_string	*argv;
	char		bash_cmd[500];
	int			ret;
	uint32_t	argc;

	ft_printf("testing [%s]:\n\t", line->str);
	argv = parser(mshell, line, &argc);
	if (argv == NULL)
		return (ft_printf("parse returned NULL"));
	mshell_parser_single_replace(line);
	sprintf(bash_cmd, "echo \"%s\" | /bin/bash 2>&1", line->str);
	bash_file = popen(bash_cmd, "r");
	if (!bash_file)
		return (ft_printf("failed to execute bash command"));
	ret = mshell_parser_single_test_res(argc - 1, &argv[1], bash_file);
	mshell_parser_single_free(argc, argv);
	ft_printf("%s\n\n", !ret ? "passed!" : "");
	return (ret);
}
