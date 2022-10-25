/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/10/25 15:56:02 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "utils.h"
# include <stdio.h>

typedef enum e_toktype
{
	TOK_ERROR,
	TOK_ARG,
	TOK_OP,
	TOK_SPACE,
	TOK_EOF,
	TOK_MAX
}	t_toktype;


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
	t_toktype		type;
	size_t			start;
	size_t			end;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char	*input;
	t_token	*tokens;
	size_t	start;
}	t_lexer;

void	lexer(t_lexer *lexer);
void	tokenizer(t_lexer *lexer);

/**
 * Token list functions.
 */

int		token_size(t_token *token);
void	token_delone(t_token *token, void (*del)(void*));
void	tokenclear(t_token **token, void (*del)(void*));
t_token	*token_new(char *word, t_toktype type);
int		token_addafter(t_token **spot, t_token *new);
t_token	*token_last(t_token *token);
t_token	*token_first(t_token **token);
int		token_append(t_token **token, t_token *new);
void	token_prepend(t_token **token, t_token *new);
t_token	*token_remove(t_token **head, t_token *token);

//	trying out a different version where i don't malloc the cmd itself
//	but just store the start and end index  of that token in the original
//	input string

t_token	*token_new2(size_t start, t_toktype type);

// want to make a lookup table for the character token types
// and this is my attempt
typedef

void	print_tokens(t_token *tokens, size_t len);

#endif