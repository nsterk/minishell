
#include "lexer.h"

static t_toktype	st_get_type(t_lexstate state);
static bool			st_lexfunction(t_lexer *lexer, t_toktype type);

bool	lexer(t_lexer *lexer)
{
	while (ft_isspace(lexer->str[lexer->idx]))
		lexer->idx++;
	lexer->state = get_state(lexer->str[lexer->idx]);
	while (lexer->state != S_EOF)                                                                       
	{
		if (st_lexfunction(lexer, st_get_type(lexer->state)))
			return (true);
	}
	return (false);
}

t_lexstate	get_state(int c)
{
	if (c == '\0')
		return (S_EOF);
	if (ft_isspace(c))
		return (S_SPACE);
	if (c == CH_SQUOTE)
		return (S_SQUOTE);
	if (c == CH_DQUOTE)
		return (S_DQUOTE);
	if (c == CH_LESS)
		return (S_REDIR_IN);
	if (c == CH_GREAT)
		return (S_REDIR_OUT);
	if (c == CH_PIPE)
		return (S_PIPE);
	return (S_WORD);
}

void	switch_state(t_lexer *lexer, t_lexstate new_state)
{
	lexer->state = new_state;
	lexer->idx++;
}

static t_toktype	st_get_type(t_lexstate state)
{
	static const t_toktype	s_type[] = {
	[S_SPACE] = TOK_SPACE,
	[S_SQUOTE] = TOK_SQUOTE,
	[S_DQUOTE] = TOK_DQUOTE,
	[S_REDIR_IN] = TOK_REDIR_IN,
	[S_REDIR_OUT] = TOK_REDIR_OUT,
	[S_PIPE] = TOK_PIPE,
	[S_WORD] = TOK_WRD,
	[S_EOF] = TOK_EOF
	};

	return (s_type[state]);
}

static bool	st_lexfunction(t_lexer *lexer, t_toktype type)
{
	static const t_lexfunction lex[] = {
		[TOK_SPACE] = &lex_space,
		[TOK_WRD] = &lex_word,
		[TOK_SQUOTE] = &lex_quote,
		[TOK_DQUOTE] = &lex_quote,
		[TOK_REDIR_IN] = &lex_operator,
		[TOK_REDIR_OUT] = &lex_operator,
		[TOK_PIPE] = &lex_operator
	};
	return (lex[type](lexer, type));
}
