/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:01:51 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 09:33:05 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
**	Test the lexer with input from a file. If no file is given some random
**	tests will be preformed.
**
**	@param {char *} filename - NULL if no file is specified
**
**	@return {int} - 0 if everything passed, a positive value with the amount
**		of tests which failed, or a negative value when somehing else failed.
*/

int			mshell_lexer(char *filename)
{
	if (filename)
		return (mshell_lexer_file(filename));
	return (mshell_lexer_rand());
}
