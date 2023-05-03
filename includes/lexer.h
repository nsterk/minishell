/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/05/03 13:09:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include <stdbool.h>

typedef enum e_toktype
{
	TOK_WRD,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_PIPE,
	TOK_SPACE,
	TOK_EOF,
	TOK_MAX
}	t_toktype;

typedef enum e_lexstate
{
	S_SPACE,
	S_REDIR_IN,
	S_REDIR_OUT,
	S_PIPE,
	S_WORD,
	S_DQUOTE,
	S_SQUOTE,
	S_EOF
}	t_lexstate;

typedef struct s_expansion
{
	size_t	start;
	size_t	end;
	char 	*parameter;
}	t_expansion;

typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char			*word;
	size_t			exp_count;
	t_toktype		type;
	t_lexstate		state;
	int				flags;
	t_expansion		*exp;
}	t_token;

typedef struct s_lexer
{
	char		*str;
	t_token		*tokens;
	size_t		idx;
	size_t		expansions;
	t_lexstate	state;
	int			flags;
	char		**envp;
}	t_lexer;

bool		lexer(t_lexer *lexer);
t_lexstate	get_state(int c);
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

t_token		*token_new(t_toktype type, t_lexstate state, char *str, size_t exps);
int			token_size(t_token *token);
void		token_delone(t_token *token, void (*del)(void*));
void		tokenclear(t_token **token, void (*del)(void*));
int			token_addafter(t_token **spot, t_token *new);
t_token		*token_last(t_token *token);
t_token		*token_first(t_token **token);
int			token_append(t_token **token, t_token *new);
// void		token_prepend(t_token **token, t_token *new);
t_token		*token_remove(t_token **head, t_token *token);

#endif