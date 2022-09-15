/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/15 21:54:39 by nsterk        ########   odam.nl         */
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
	char			*word;
	t_type			type;
}	t_token;

typedef struct s_lexer
{
	char	*input;
	char	**words;
	t_token	*tokens;
	size_t	nr_tokens;
}	t_lexer;

void	lexer(t_lexer *lexer);
void	fill_tokens(t_token *tokens, char **words, size_t len);
void	print_tokens(t_token *tokens, size_t len);


#endif