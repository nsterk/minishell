/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_word.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:51 by nsterk        #+#    #+#                 */
/*   Updated: 2023/05/03 12:48:33 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool		error_msg(char *msg);

static bool	s_lex_quote(t_lexer *lex, int quote)
{
	size_t	start;

	lex->idx++;
	if (!ft_strchr(lex->str + lex->idx, quote))
		return (error_msg("Unclosed quotes not supported by momoshell"));
	start = lex->idx;
	if (lex->state == S_DQUOTE && lex->str[start] == CH_EXPAND)
		lex->expansions++;
	while (lex->str[lex->idx + 1] && lex->str[lex->idx + 1] != quote)
	{
		lex->idx++;
		if (lex->state == S_DQUOTE && lex->str[lex->idx] == CH_EXPAND)
			lex->expansions++;
	}
	delimit_token(lex, start, TOK_WRD);
	lex->idx++;
	return (false);
}

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	if ((lexer->state == S_SQUOTE || lexer->state == S_DQUOTE))
	{
		if (s_lex_quote(lexer, lexer->str[start])) 
			return (true);
	}
	else
	{
		while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
		{
			if (lexer->str[lexer->idx] == CH_EXPAND)
				lexer->expansions++;
			lexer->idx++;
		}
		delimit_token(lexer, start, type);
	}
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
