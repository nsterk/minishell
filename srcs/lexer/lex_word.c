/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_word.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:51 by nsterk        #+#    #+#                 */
/*   Updated: 2023/05/01 18:50:57 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	s_lex_quote(t_lexer *lexer, int quote)
{
	size_t	start;

	lexer->idx++;
	if (!ft_strchr(lexer->str + lexer->idx, quote))
		return (error_msg("Unclosed quotes not supported by momoshell"));
	start = lexer->idx;
	while (lexer->str[lexer->idx + 1] && lexer->str[lexer->idx + 1] != quote)
			lexer->idx++;
	delimit_token(lexer, start, TOK_WRD);
	lexer->idx++;
	return (false);
}

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	if ((lexer->state == S_SQUOTE || lexer->state == S_DQUOTE) && \
		s_lex_quote(lexer, lexer->str[start])) 
		return (true);
	else
	{
		while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
		{
			if (lexer->str[lexer->idx] == CH_EXPAND)
				lexer->exp_loc = lexer->idx;
			lexer->idx++;
		}
		delimit_token(lexer, start, type);
	}
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
