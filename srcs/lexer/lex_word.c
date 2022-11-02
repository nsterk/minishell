/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_word.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:51 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/02 22:13:43 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	while (lexer->state == get_state(lexer->input[lexer->idx + 1]))
		lexer->idx++;
	if (token_append(&(lexer->tokens), token_new2(start, lexer->idx, type)))
		exit(EXIT_FAILURE);
	switch_state(lexer, get_state(lexer->input[lexer->idx + 1]));
	return (true);
}
