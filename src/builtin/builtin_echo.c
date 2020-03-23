/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:47:25 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 14:28:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

char	*echo_cat(char **args, uint32_t nargs, uint32_t start)
{
	char		*res;
	size_t		wordlen;
	uint32_t	i;
	uint32_t	j;
	uint32_t	len;

	len = 0;
	i = start;
	while (i < nargs + 1)
	{
		len += ft_strlen(args[i]);
		len++;
		i++;
	}
	len--;
	res = malloc(len + 1);
	i = start;
	j = 0;
	while (i < nargs + 1)
	{
		wordlen = ft_strlen(args[i]);
		ft_memcpy(res + j, args[i], wordlen);
		j += wordlen;
		res[j] = (i < nargs) ? ' ' : '\0';
		j++;
		i++;
	}
	return (res);
}

void	builtin_echo(char **args, uint32_t nargs)
{
	bool	has_n;
	char	*str;

	if (nargs == 0)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	has_n = !ft_strcmp(args[1], "-n");
	str = echo_cat(args, nargs, has_n ? 2 : 1);
	ft_putstr_fd(str, 1);
	free(str);
	if (!has_n)
		ft_putchar_fd('\n', 1);
}
