/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_word.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:51 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/06 21:25:59 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	lex_quote(t_lexer *lexer, int quote)
{
	size_t	start;

	lexer->idx++;
	if (!ft_strchr(lexer->str + lexer->idx, quote))
		exit(EXIT_FAILURE); //!fugly
	start = lexer->idx;
	while (lexer->str[lexer->idx + 1] && lexer->str[lexer->idx + 1] != quote)
			lexer->idx++;
	delimit_token(lexer, start, TOK_CMD);
	lexer->idx++;
}

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	if (lexer->state == S_SQUOTE || lexer->state == S_DQUOTE)
		lex_quote(lexer, lexer->str[start]);
	else
	{
		while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
			lexer->idx++;
		delimit_token(lexer, start, type);
	}
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (true);
}
