/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:12:07 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 13:13:43 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

int				mshell_lexer(char *filename);

typedef struct	s_test {
	char	*label;
	int		(*test_func)(char *fname);
	bool	fname_req;
}				t_test;

t_test			g_tests[] = {
	{ "lexer",			mshell_lexer,		false },
	{ NULL,				NULL,				false },
};

#endif
