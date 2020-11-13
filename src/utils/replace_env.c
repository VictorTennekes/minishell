/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 19:07:02 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/11/13 10:33:15 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmd.h>
#include <env.h>
#include <libft.h>
#include <stdlib.h>

static char	*replace_str_single(char *src, char *to_find, char *start,
									char *replace)
{
	size_t	to_find_len;
	size_t	replace_len;
	char	*res;

	if (!src || !to_find || !replace)
		return (NULL);
	to_find_len = ft_strlen(to_find);
	replace_len = ft_strlen(replace);
	if (!to_find_len)
		return (NULL);
	res = malloc(sizeof(char) * ft_strlen(src)
			+ (replace_len - to_find_len) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, (start - src) + 1);
	ft_strlcpy(res + (start - src), replace, replace_len + 1);
	ft_strlcpy(res + (start - src) + replace_len, start + to_find_len,
				ft_strlen(src) - ((start - src) + to_find_len) + 1);
	free(src);
	return (res);
}

static char	*loop_env(t_mshell *mshell, char *str)
{
	t_env	*env;
	char	*res;

	env = env_get(mshell, str);
	if (!env)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * env->value.len + 1);
	ft_strlcpy(res, env->value.str, env->value.len + 1);
	return (res);
}

int			valid_env_size(char *str)
{
	int i;

	i = 1;
	if (str[i] >= '0' && str[i] <= '9')
		return (2);
	while (((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			((str[i] >= '0' && str[i] <= '9')) ||
			str[i] == '_') || str[i] == '?')
		i++;
	return (i);
}

static char	*subst_env(t_mshell *mshell, char **command, char *pos,
		char *to_find)
{
	int		len;
	char	*replace;

	if (!to_find)
		return (NULL);
	len = valid_env_size(pos);
	if (len <= 1)
		return (NULL);
	ft_strlcpy(to_find, pos, len + 1);
	len += pos - *command;
	replace = loop_env(mshell, to_find + 1);
	if (!replace)
		error(E_ALLOC "'subst_env'", mshell);
	*command = replace_str_single(*command, to_find, pos, replace);
	len = (len - ft_strlen(to_find)) + ft_strlen(replace);
	free(replace);
	if (!ft_strchr(*command + len - 1, '$'))
		return (NULL);
	pos = ft_strchr(*command + len - 1, '$');
	return (pos);
}

void		replace_env(t_mshell *mshell, t_string *str, int32_t start)
{
	char	*pos;
	char	*to_find;

	to_find = malloc(sizeof(char) * (str->len + 1));
	pos = ft_strchr(str->str + (start == -1 ? 0 : start), '$');
	while (pos)
		pos = subst_env(mshell, &str->str, pos, to_find);
	str->len = ft_strlen(str->str);
	str->cap = str->len;
	free(to_find);
}
