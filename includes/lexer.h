/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/15 20:21:19 by nsterk        ########   odam.nl         */
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
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char	*input;
	t_token	*tokens;
}	t_lexer;

t_token	*lexer(void);

#endif