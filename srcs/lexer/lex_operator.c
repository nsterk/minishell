
#include "lexer.h"

bool	lex_operator(t_lexer *lex, t_toktype type)
{
	const size_t	start = lex->idx;
	const char		c = lex->str[lex->idx];

	if (type != TOK_PIPE && c == lex->str[lex->idx + 1])
	{
		lex->flags |= F_APPEND;
		lex->idx++;
	}
	lex->flags |= F_OPERATOR;
	delimit_token(lex, start, type);
	switch_state(lex, get_state(lex->str[lex->idx + 1]));
	return (false);
}
