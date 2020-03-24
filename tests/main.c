/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:11:36 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 16:58:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <libft.h>
#include <libftprintf.h>

int		main(int argc, char *argv[])
{
	uint32_t	i;

	if (argc < 2 || argc > 3)
	{
		ft_printf("Usage: ./test test-name [filename]\n");
		return (1);
	}
	i = 0;
	while (g_tests[i].label)
	{
		if (!ft_strcmp(argv[1], g_tests[i].label))
		{
			if (argc == 2 && g_tests[i].fname_req)
			{
				ft_printf("File is required for test \"%s\"\n",
						g_tests[i].label);
				return (1);
			}
			else
				return (g_tests[i].test_func(argc == 2 ? NULL : argv[2]));
		}
		i++;
	}
	ft_printf("Invalid test name: %s\n", argv[1]);
	return (1);
}
