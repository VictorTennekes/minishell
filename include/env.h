/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:19:26 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/02 16:22:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <minishell.h>

# define ENV_PRINT_INIT_CAP (2000)

typedef struct	s_env {
	bool		read_only;
	t_string	name;
	t_string	value;
}				t_env;

bool	env_unset(t_mshell *mshell, char *name, bool enforce_ro);
t_env	*env_get(t_mshell *mshell, char *name);
t_env	*env_set(t_mshell *mshell, char *name, char *value, bool read_only);

#endif
