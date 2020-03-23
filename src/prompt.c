/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 13:26:37 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/23 13:27:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

/*
**	Prints the prompt to stdout.
*/

void	prompt(void)
{
	ft_putstr_fd("> ", 1);
}
