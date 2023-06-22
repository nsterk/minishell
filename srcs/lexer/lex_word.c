
#include "minishell.h"

static bool	st_is_file(t_lexer *lexer);

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;
	bool	filename;

	start = lexer->idx;
	filename = st_is_file(lexer);
	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
	{
		if (!filename && lexer->str[lexer->idx] == CH_EXPAND)
			lexer->expansions++;
		lexer->idx++;
	}
	delimit_token(lexer, start, type);
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}

static bool	st_is_file(t_lexer *lexer)
{
	t_token	*last;

	last = token_last(lexer->tokens);
	if (!last)
		return (false);
	if (last->type == TOK_REDIR_IN || last->type == TOK_REDIR_OUT)
		return (true);
	if (last->type == TOK_SPACE && last->prev)
	{
		if (last->prev->type == TOK_REDIR_IN || last->prev->type == TOK_REDIR_OUT)
			return (true);
	}
	return (false);
}
