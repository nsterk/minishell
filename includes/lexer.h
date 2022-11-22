/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/11/22 14:08:39 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "utils.h"
# include <stdbool.h>
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

// typedef enum e_toktype
// {
// 	TOK_ERROR,
// 	TOK_CMD,
// 	TOK_ARG,
// 	TOK_RIN,
// 	TOK_ROUT,
// 	TOK_PIPE,
// 	TOK_SPACE,
// 	TOK_EOF,
// 	TOK_MAX
// }	t_toktype;

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
	char		**envp;
}	t_lexer;

void		lexer(t_lexer *lexer);
void		tokenizer(t_lexer *lexer);
t_lexstate	get_state(char c);

// Lexer functions and dispatch table to these functions.

typedef bool	(*t_lexfunction)(t_lexer *lexer, t_toktype type);
bool		lex_operator(t_lexer *lexer, t_toktype type);
bool		lex_word(t_lexer *lexer, t_toktype type);
bool		lex_space(t_lexer *lexer, t_toktype type);

void		switch_state(t_lexer *lexer, t_lexstate new_state);

/**
 * Token list functions.
 */

int			token_size(t_token *token);
void		token_delone(t_token *token, void (*del)(void*));
void		tokenclear(t_token **token, void (*del)(void*));
t_token		*token_new(char *word, t_toktype type);
int			token_addafter(t_token **spot, t_token *new);
t_token		*token_last(t_token *token);
t_token		*token_first(t_token **token);
int			token_append(t_token **token, t_token *new);
void		token_prepend(t_token **token, t_token *new);
t_token		*token_remove(t_token **head, t_token *token);

//	trying out a different version where i don't malloc the cmd itself
//	but just store the start and end index  of that token in the original
//	input string

t_token		*token_new2(size_t start, size_t end, t_toktype type);

t_toktype	get_type(char c);

void		print_tokens(t_token *tokens, size_t len);

#endif