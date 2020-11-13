/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:43 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/11 16:52:49 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <libft.h>
# include <stdbool.h>

int	write_string(char **tgt, char **format, int fd);
int	ft_putchar_fd_count(char **tgt, char c, int fd);
int	ft_puthex_fd_count(char **tgt, unsigned long long n, bool cap, int fd);
int	ft_putnbr_ll_fd_count(char **tgt, long long int n, int fd);
int	ft_putstr_fd_count(char **tgt, char *str, int fd);
int	ft_putstr_n_fd_count(char **tgt, char *str, size_t n, int fd);
int	ft_putunsigned_fd_count(char **tgt, unsigned long long n, int fd);
int	ftp_write(char *to_write, char **target, size_t n, int fd);

#endif
