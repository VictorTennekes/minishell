/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:12:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 21:30:32 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

int				mshell_env(char *filename);
int				mshell_parser(char *filename);

typedef struct	s_test {
	char	*label;
	int		(*test_func)(char *fname);
	bool	fname_req;
}				t_test;

t_test			g_tests[] = {
	{ "parser",			mshell_parser,		false },
	{ "env",			mshell_env,			false },
	{ NULL,				NULL,				false },
};

#endif
