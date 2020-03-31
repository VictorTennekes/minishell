/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:11:18 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 16:13:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASER_H
# define PASER_H

# include <libstring.h>
# include <libvla.h>
# include <stdbool.h>

# define PARSER_INIT_WORD_CAP (100)
# define PARSER_ARGV_INIT_CAP (10)

typedef struct	s_parser {
	bool		done;
	bool		end_word;
	bool		in_dquote;
	bool		in_squote;
	bool		in_word;
	bool		new_word;
	t_string	*curr_word;
	t_vla		result;
	uint32_t	argc;
}				t_parser;

/*
**	Push a character to the end of the current word.
**
**	@param {t_parser *} parser
**	@param {char} c
*/

void		parser_push(t_parser *parser, char c);


/*
**	Push a new (empty) word on top of the list.
**
**	@param {t_parser *} parser
*/

void		parser_new_word(t_parser *parser);


/*
**	Terminate the current word. This shrinks it to the minimum size required
**	and sets the appropiate flags.
**
**	@param {t_parser *} parser
*/

void		parser_end_word(t_parser *parser);

/*
**	All of the cases for the parser. Every case corresponds to a single, or
**	multiple characters in the input string. The 'rest' case is defined
**	for every character for which no case is defined.
**
**	@param {t_parser *} parser
**	@param {char} c
**
**	@return {bool} true if an error is encountered
*/

bool		parser_case_end(t_parser *parser, char c);
bool		parser_case_rest(t_parser *parser, char c);
bool		parser_case_whitespace(t_parser *parser, char c);
bool		parser_case_squote(t_parser *parser, char c);
bool		parser_case_dquote(t_parser *parser, char c);


typedef struct	s_parser_case {
	char	c;
	bool	(*func)(t_parser *, char);
}				t_parser_case;

#endif
