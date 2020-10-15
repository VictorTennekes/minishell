#include <minishell.h>
#include <libft.h>

t_builtin	g_builtins[] = {
	{ "cd", 	builtin_cd },
	{ "echo", 	builtin_echo },
	{ "env", 	builtin_env },
	{ "exit", 	builtin_exit },
	{ "export", builtin_export },
	{ "pwd", 	builtin_pwd },
	{ "unset", 	builtin_unset },
	{ NULL , 	NULL },
};

t_builtin_func	find_builtin(t_string name)
{
	size_t	i;

	i = 0;
	while (g_builtins[i].cmd != NULL)
	{
		if (ft_strcmp(name.str, g_builtins[i].cmd) == 0)
			return (g_builtins[i].func);
		i++;
	}
	return (NULL);
}

