/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/11/24 21:30:24 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>
# include "utils.h"
# include <stdio.h>

typedef enum e_toktype
{
	TOK_CMD,
	TOK_OP,
	TOK_SPACE,
	TOK_EOF,
	TOK_MAX
}	t_toktype;

typedef enum e_lexstate
{
	S_SPACE,
	S_OPERATOR,
	S_WORD,
	S_DQUOTE,
	S_SQUOTE,
	S_EOF
}	t_lexstate;

typedef struct s_token
{
	struct s_token	*prev;
	char			*word;
	size_t			start;
	size_t			end;
	struct s_token	*next;
	t_toktype		type;
}	t_token;

typedef struct s_lexer
{
	char		*input;
	t_token		*tokens;
	size_t		idx;
	t_lexstate	state;
}	t_lexer;

void		lexer(t_lexer *lexer);
void		tokenizer(t_lexer *lexer);
t_lexstate	get_state(char c);
void		delimit_token(t_lexer *lexer, size_t start, t_toktype type);

// Lexer functions and dispatch table to these functions.

typedef bool	(*t_lexfunction)(t_lexer *lexer, t_toktype type);
bool		lex_operator(t_lexer *lexer, t_toktype type);
bool		lex_word(t_lexer *lexer, t_toktype type);
bool		lex_space(t_lexer *lexer, t_toktype type);

void		switch_state(t_lexer *lexer, t_lexstate new_state);

/**
 * Token list functions.
 */

t_token		*token_new(size_t start, size_t end, t_toktype type);
int			token_size(t_token *token);
void		token_delone(t_token *token, void (*del)(void*));
void		tokenclear(t_token **token, void (*del)(void*));
int			token_addafter(t_token **spot, t_token *new);
t_token		*token_last(t_token *token);
t_token		*token_first(t_token **token);
int			token_append(t_token **token, t_token *new);
void		token_prepend(t_token **token, t_token *new);
t_token		*token_remove(t_token **head, t_token *token);

t_toktype	get_type(char c);

void		print_tokens(t_token *tokens, size_t len);

#endif