/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:47:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 19:19:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

/*
**	Copy the given src string to dst until the '\0' char. Does not terminate
**	it.
**
**	@param {char *} dst
**	@param {char *} src
*/

static uint32_t echo_cpy(char *dst, char *src)
{
	uint32_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

/*
**	Calculate the length of the total string which echo will output.
**
**	@param {uint32_t} word_count
**	@param {char *[]} words
*/

static uint32_t	echo_cat_len(uint32_t word_count, char *words[])
{
	uint32_t	res;
	uint32_t	i;

	i = 0;
	res = 0;
	while (i < word_count)
	{
		res += ft_strlen(words[i]) + 1;
		i--;
	}
	return (res);
}

/*
**	Concatenate all of the arguments of the echo call into one string,
**	seperated by spaces (' '). The returned pointer is to an allocated
**	string.
**
**	@param {uint32_t} word_count - the amount of words in the array
**	@param {char *[]} words
*/

static char		*echo_cat(uint32_t word_count, char *words[])
{
	char		*res;
	uint32_t	i;
	uint32_t	j;

	res = malloc(echo_cat_len(word_count, words));
	if (!res)
		error("Allocation failed in 'echo_cat'");
	i = 0;
	j = 0;
	while (i < word_count)
	{
		j += echo_cpy(&res[j], words[i]) + 1;
		res[j - 1] = (i + 1 < word_count) ? ' ' : '\0';
		i++;
	}
	return (res);
}

/*
**	The echo function built into the shell. Should function the same as in
**	bash, except it only has to handle the '-n' flag.
**
**	@param {uint32_t} argc
**	@param {char *[]} argv
*/

void			builtin_echo(uint32_t argc, char *argv[])
{
	bool	has_n;
	char	*str;

	if (argc == 1)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	has_n = !ft_strcmp(argv[0], "-n");
	str = echo_cat(argc - has_n - 1, &argv[has_n]);
	ft_putstr_fd(str, 1);
	free(str);
	if (!has_n)
		ft_putchar_fd('\n', 1);
}
