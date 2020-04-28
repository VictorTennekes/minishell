/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:    :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:12:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/28 09:50:15 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <minishell.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

int				mshell_env(t_mshell *mshell, char *filename);
int				mshell_parser(t_mshell *mshell, char *filename);

typedef struct	s_test {
	char	*label;
	int		(*test_func)(t_mshell *mshell, char *fname);
	bool	fname_req;
}				t_test;

t_test			g_tests[] = {
	{ "parser",			mshell_parser,		false },
	{ "env",			mshell_env,			false },
	{ NULL,				NULL,				false },
};

#endif
