/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:20 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 16:30:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <utils.h>

int	start(char *str, const char *format, va_list *args, int fd)
{
	int res;

	res = 0;
	while (*format)
	{
		res += write_string(str ? &str : NULL, (char **)&format, fd);
		if (*format == '%')
			res += handle_format(str ? &str : NULL, (char **)&format,
					(t_format_func_args){{}, args, res, fd});
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = start(NULL, format, &args, FD);
	va_end(args);
	return (res);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = start(NULL, format, &args, fd);
	va_end(args);
	return (res);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = start(str, format, &args, FD);
	va_end(args);
	return (res);
}
