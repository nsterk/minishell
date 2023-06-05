
#include "lexer.h"
bool	error_msg(char *msg);

bool	lex_quote(t_lexer *lexer, t_toktype type)
{
	size_t	start;
	int		quote;

	quote = lexer->str[lexer->idx];
	if (!ft_strchr(lexer->str + lexer->idx + 1, quote))
		return (error_msg("Unclosed quotes not supported by momoshell"));
	lexer->idx++;
	start = lexer->idx;
	if (type == TOK_DQUOTE && lexer->str[start] == CH_EXPAND)
		lexer->expansions++;
	while (lexer->str[lexer->idx + 1] != quote)
	{
		lexer->idx++;
		if (quote == CH_DQUOTE && lexer->str[lexer->idx] == CH_EXPAND)
			lexer->expansions++;
	}
	delimit_token(lexer, start, type);
	lexer->idx++;
	// lexer->idx--;
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
