/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 11:11:18 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 13:36:16 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libstring.h>
# include <libvla.h>
# include <minishell.h>
# include <stdbool.h>

# define PARSER_INIT_WORD_CAP 100
# define PARSER_ARGV_INIT_CAP 10
# define PARSER_CMDS_INIT_CAP 4
# define PARSER_FILES_INIT_CAP 3

typedef struct	s_parser {
	bool		done;
	bool		end_word;
	bool		in_dquote;
	bool		in_squote;
	bool		in_word;
	bool		new_cmd;
	bool		new_word;
	bool		redir;
	int			redir_type;
	bool		pipe;
	bool		expand_env;
	bool		escaped;
	t_string	*curr_word;
	t_vla		redir_files;
	t_vla		curr_cmd;
	t_vla		result;
}				t_parser;

typedef bool	(*t_parser_check)(t_mshell *, t_cmd **, size_t *);

/*
**	Push a character to the end of the current word.
**
**	@param {t_parser *} parser
**	@param {char} c
*/

void			parser_push(t_mshell *mshell, t_parser *parser, char c);

/*
**	Push a new (empty) word on top of the list.
**
**	@param {t_parser *} parser
*/

void			parser_new_word(t_mshell *mshell, t_parser *parser);

/*
**	Terminate the current word. This shrinks it to the minimum size required
**	and sets the appropiate flags.
**
**	@param {t_parser *} parser
*/

void			parser_end_word(t_mshell *mshell, t_parser *parser);

/*
**	Terminate the current command. This shrinks the current command sto the
**	minimum size required and sets the appropiate flags.
*/

void			parser_new_cmd(t_mshell *mshell, t_parser *parser, bool init);

void			parser_push_cmd(t_mshell *mshell, t_parser *parser);

void			parser_check(t_mshell *mshell, t_cmd **result,
		size_t *cmd_count);

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

bool			parser_case_end(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_rest(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_whitespace(t_mshell *mshell, t_parser *parser,
					char c);
bool			parser_case_squote(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_dquote(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_semicolon(t_mshell *mshell, t_parser *parser,
					char c);
bool			parser_case_pipe(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_write(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_input(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_env(t_mshell *mshell, t_parser *parser, char c);
bool			parser_case_escape(t_mshell *mshell, t_parser *parser, char c);

typedef struct	s_parser_case {
	char	c;
	bool	(*func)(t_mshell *, t_parser *, char);
}				t_parser_case;

#endif
