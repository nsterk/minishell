
#include "lexer.h"

bool	lex_space(t_lexer *lexer, t_toktype type)
{
	(void)type;
	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
		lexer->idx++;
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
