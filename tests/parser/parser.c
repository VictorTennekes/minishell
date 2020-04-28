/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/24 09:01:51 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 09:32:40 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
**	Test the parser with input from a file. If no file is given some random
**	tests will be preformed.
**
**	@param {t_mshell *} mshell
**	@param {char *} filename - NULL if no file is specified
**
**	@return {int} - 0 if everything passed, a positive value with the amount
**		of tests which failed, or a negative value when somehing else failed.
*/

int			mshell_parser(t_mshell *mshell, char *filename)
{
	if (filename)
		return (mshell_parser_file(mshell, filename));
	return (mshell_parser_rand());
}
