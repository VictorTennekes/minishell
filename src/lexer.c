/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 19:49:13 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 09:48:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libvla.h>
#include <minishell.h>
#include <stdlib.h>

static void	lex_word_cpy(char *word, char *cmd, uint32_t len)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (cmd[i] == '\\')
		{
			if (cmd[i + 1] == '\\')
			{
				word[j] = '\\';
				j++;
			}
		}
		else
		{
			word[j] = cmd[i];
			j++;
		}
		i++;
	}
}

static uint32_t	lex_word_len(char *cmd, char to_find, bool *found_end)
{
	uint32_t	res;
	uint32_t	i;

	res = 0;
	i = 0;
	while (cmd[i] != to_find && cmd[i])
	{
		if (cmd[i] == '\\')
		{
			if (cmd[i + 1] == '\\')
			{
				res++;
				i++;
			}
		}
		else
			res++;
		i++;
	}
	if (!cmd[i] && found_end != NULL)
		*found_end = true;
	return (res);
}

static void		lex_quote(char *cmd, t_vla *res, uint32_t *index)
{
	bool		found_end;
	char		*word;
	uint32_t	len;

	found_end = false;
	len = lex_word_len(&cmd[1], *cmd, &found_end);
	if (found_end)
		error("Invalid command. Could not find trailing quote.");
	word = malloc(len);
	if (!word)
		error("Allocation failed in 'split_args_word'");
	cmd += sizeof(char);
	lex_word_cpy(word, cmd, len);
	*index += len + 2;
	if (vla_push(res, &word, NULL))
		error("Allocation failed in 'split_args_word'");
}

/*
**	Will lex a single word, which is not 
*/

static void		lex_word(char *cmd, t_vla *res, uint32_t *index)
{
	char		*word;
	uint32_t	len;

	len = lex_word_len(cmd, ' ', NULL);
	word = malloc(len);
	if (!word)
		error("Allocation failed in 'split_args_word'");
	lex_word_cpy(word, cmd, len);
	*index += len;
	if (vla_push(res, &word, NULL))
		error("Allocation failed in 'split_args_word'");
}

/*
**	The lexer for the initial input of the shell. Because we will not implement
**	any logix into the shell, the lexer only knows one type of token; a string.
**	This function will tokenize the command into strings and return the final
**	array.
**
**	@param {char *} cmd - will not be freed here
**	@param {uint32_t *} argc - will be set to the amount of elements in the
**		result array.
*/

char			**lex(char *cmd, uint32_t *argc)
{
	t_vla		res;
	uint32_t	i;

	if (vla_init(sizeof(char *), ARGV_INIT_CAP, &res))
		error("Allocation failed in 'split_args'");
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ' || cmd[i] == '\t')
			i++;
		(cmd[i] == '\'' || cmd[i] == '\"' ? lex_quote : lex_word)
			(&cmd[i], &res, &i);
	}
	vla_shrink(&res);
	*argc = res.size;
	return (res.vla);
}
