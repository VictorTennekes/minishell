/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:31:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 09:33:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

int		mshell_lexer_file(char *filename);
int		mshell_lexer_single(char *line);
int		mshell_lexer_rand(void);

#endif
