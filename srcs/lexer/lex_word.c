
#include "minishell.h"

static bool	st_check_heredoc(t_token *last);
static void	st_check_filename(t_lexer *lexer, t_token *last, bool heredoc);

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	size_t	start;
	t_token	*last;
	bool	heredoc;

	start = lexer->idx;
	last = token_last(lexer->tokens);
	heredoc = st_check_heredoc(last);
	st_check_filename(lexer, last, heredoc);
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

static bool	st_check_heredoc(t_token *last)
{
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

static void	st_check_filename(t_lexer *lexer, t_token *last, bool heredoc)
{
	if (!last)
		return ;
	if ((last->type == TOK_REDIR_IN && !heredoc) || last->type == TOK_REDIR_OUT)
		lexer->flags |= F_FILENAME;
	else if (last->flags & F_SPACE && last->prev)
	{
		if ((last->prev->type == TOK_REDIR_IN && !heredoc) || \
			last->prev->type == TOK_REDIR_OUT)
			lexer->flags |= F_FILENAME;
	}
}
