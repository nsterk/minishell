
#include "minishell.h"

/**
 * @brief Het moet JUIST expanded worden als het een filename is.
 * It should not be expanded if it's a delimiter - of iig I'm not going to do that
 * Alleen als heredoc ga ik het niet proberen te expanden. In alle andere gevallen:
 * 
 * 1. mark as expansion
 * 2. tijdens expander aparte casus voor als het een ambiguous redirect is 
 */

static bool	st_is_heredoc(t_lexer *lexer);

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;
	bool	heredoc;

	start = lexer->idx;
	heredoc = st_is_heredoc(lexer);
	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
	{
		if (!heredoc && lexer->str[lexer->idx] == CH_EXPAND)
			lexer->expansions++;
		lexer->idx++;
	}
	delimit_token(lexer, start, type);
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}

static bool	st_is_heredoc(t_lexer *lexer)
{
	t_token	*last;

	last = token_last(lexer->tokens);
	if (!last)
		return (false);
	if (last->type == TOK_REDIR_IN && last->flags & F_APPEND)
		return (true);
	if (last->type == TOK_SPACE && last->prev)
	{
		if (last->prev->type == TOK_REDIR_IN && \
			last->prev->flags & F_APPEND)
			return (true);
	}
	return (false);
}
