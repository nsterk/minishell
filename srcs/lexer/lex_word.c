
#include "minishell.h"

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;

	start = lexer->idx;
	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
	{
		if (lexer->str[lexer->idx] == CH_EXPAND)
			lexer->expansions++;
		lexer->idx++;
	}
	delimit_token(lexer, start, type);
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
