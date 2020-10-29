/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 20:35:11 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/06/02 15:47:43 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include <minishell.h>

char	*path_find_file(t_mshell *mshell, char *name,
		bool executable);
char	*path_new(t_mshell *mshell, char *value, bool update_env);
void	path_update_from_env(t_mshell *mshell);

#endif
