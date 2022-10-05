/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/10/05 19:23:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "utils.h"
# include <stdio.h>

typedef enum e_type
{
	I_RED,
	WORD,
	PIPE,
	HERE_DOC,
	O_RED,
	C_EOF
}	t_type;

typedef struct s_token
{
	struct s_token	*prev;
	char			*word;
	t_type			type;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char	*input;
	char	**words;
	t_token	*tokens;
	size_t	nr_tokens;
}	t_lexer;

void	lexer(t_lexer *lexer);
void	fill_tokens(t_lexer *lexer);
// void	print_tokens(t_token *tokens, size_t len);

/**
 * Token list functions.
 */

int		token_size(t_token *token);
void	token_delone(t_token *token, void (*del)(void*));
void	tokenclear(t_token **token, void (*del)(void*));
t_token	*token_new(char *word);
int		token_addafter(t_token **spot, t_token *new);
t_token	*token_last(t_token *token);
t_token	*token_first(t_token **token);
int		token_append(t_token **token, t_token *new);
void	token_prepend(t_token **token, t_token *new);
t_token	*token_remove(t_token **head, t_token *token);

#endif