
#include "lexer.h"

bool		error_msg(char *msg);
static bool	st_lex_quote(t_lexer *lex, int quote);
static bool	st_right_state(t_lexer *lex);

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	while (st_right_state(lexer))
	{
		if (lexer->str[lexer->idx] == CH_SQUOTE || lexer->str[lexer->idx] == CH_DQUOTE)
		{
			if (st_lex_quote(lexer, lexer->str[lexer->idx]))
				return (true);
		}
		else
		{
			if (lexer->str[lexer->idx] == CH_EXPAND)
				lexer->expansions++;
		}
		lexer->idx++;
	}
	delimit_token(lexer, start, type);
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}

static bool	st_lex_quote(t_lexer *lex, int quote)
{
	size_t	star

	lex->idx++;
	if (!ft_strchr(lex->str + lex->idx, quote))
		return (error_msg("Unclosed quotes not supported by momoshell"));
	start = lex->idx;
	if (quote == CH_DQUOTE && lex->str[start] == CH_EXPAND)
		lex->expansions++;
	while (lex->str[lex->idx + 1] && lex->str[lex->idx + 1] != quote)
	{
		lex->idx++;
		if (quote == CH_DQUOTE && lex->str[lex->idx] == CH_EXPAND)
			lex->expansions++;
	}
	// lex->idx++;
	return (false);
}

static bool	st_right_state(t_lexer *lex)
{
	if (lex->str[lex->idx] == CH_SQUOTE || lex->str[lex->idx] == CH_DQUOTE)
		return (true);
	return (lex->state == get_state(lex->str[lex->idx + 1]));
}
