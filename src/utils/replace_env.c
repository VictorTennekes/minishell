/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:07:02 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/18 19:07:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmd.h>
#include <env.h>
#include <libft.h>
#include <stdlib.h>

#include <stdio.h>

static char		*join_str_arr(char **str)
{
	char	*res;
	size_t	i;

	res = zalloc(sizeof(char));
	i = 0;
	while (str[i])
	{
		res = ft_strjoin(res, str[i]);
		i++;
	}
	return (res);
}

static char		*loop_env(t_mshell *mshell, char *str)
{
	t_list	*env_vars;
	t_env	*env_tmp;
	char	*res;

	env_vars = mshell->env;
	while (env_vars)
	{
		env_tmp = env_vars->content;
		if (!ft_strncmp(str, env_tmp->name.str, ft_strlen(str)))
		{
			res = malloc(sizeof(char) * env_tmp->value.len);
			ft_strlcpy(res, env_tmp->value.str, env_tmp->value.len + 1);
			free(str);
			return (res);
		}
		env_vars = env_vars->next;
	}
	ft_strlcpy(str, "", 2);
	return (str);
}

void		replace_env(t_mshell *mshell, t_cmd *cmds, size_t i)
{
	size_t	j;
	size_t	n;
	char	**split_res;
	char	*res;

	j = 0;
	while (j < cmds[i].argc)
	{
		if (ft_strchr(cmds[i].argv[j].str, '$'))
		{
			split_res = ft_split(cmds[i].argv[j].str, '$');
			n = 0;
			while (split_res[n])
			{
				split_res[n] = loop_env(mshell, split_res[n]);
				n++;
			}
			res = join_str_arr(split_res);
			free_char_arr(split_res);
			cmds[i].argv[j].str = str_replace(cmds[i].argv[j].str, cmds[i].argv[j].str, res, true);
			free (res);
		}
		j++;
	}
}