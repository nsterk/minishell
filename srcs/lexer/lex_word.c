/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_word.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:51 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/06 16:22:34 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	lex_squote(t_lexer *lexer)
{
	size_t	start;

	lexer->idx++;
	start = lexer->idx;
	while (lexer->input[lexer->idx + 1] && lexer->input[lexer->idx + 1] != '\'')
			lexer->idx++;
	delimit_token(lexer, start, TOK_CMD);
	lexer->idx++;
}

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	if (lexer->state == S_SQUOTE)
		lex_squote(lexer);
	else
	{
		while (lexer->state == S_WORD && \
			lexer->state == get_state(lexer->input[lexer->idx + 1]))
			lexer->idx++;
		delimit_token(lexer, start, type);
	}
	switch_state(lexer, get_state(lexer->input[lexer->idx + 1]));
	return (true);
}
