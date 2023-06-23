
#include "expander.h"
#include "defines.h"

static bool		st_handle_token(t_token *token, char **envp);
static t_token	*st_clean_token(t_lexer *lexer, t_token **token);
static void		st_rm_tokenspace(t_lexer *lexer);

bool	expander(char **envp, t_lexer *lex)
{
	t_token		*tmp;
	// t_expander	expander;

	tmp = lex->tokens;
	// expander.envp = envp;
	while (tmp)
	{
		if (st_handle_token(tmp, envp))
			return (true);
		tmp = st_clean_token(lex, &tmp);
	}
	if (lex->tokens)
		st_rm_tokenspace(lex);
	return (false);
}

static bool	st_handle_token(t_token *token, char **envp)
{
	size_t		i;
	t_expander	expander;
	// size_t	pos;

	i = 0;
	expander.token = token;
	expander.envp = envp;
	expander.pos = 0;
	while (i < token->exp_count)
	{
		expander.exp = &(token->exp[i]);
		while (token->word[expander.pos])
		{
			if (token->word[expander.pos] == CH_EXPAND)
			{
				if (do_expanding(&expander))
					return (true);
				break ;
			}
			expander.pos++;
		}
		i++;
	}
	return (false);
}

static t_token	*st_clean_token(t_lexer *lex, t_token **token)
{
	char	*tmp;
	bool	split;

	if ((*token)->flags ^ F_WORD)
		return ((*token)->next);
	split = false;
	if ((*token)->exp_count && (*token)->flags ^ F_DQUOTE)
		split = true;
	if ((*token)->prev && (*token)->prev->flags & F_WORD)
	{
		tmp = ft_strjoin((*token)->prev->word, (*token)->word);
		check_malloc(tmp, "st_clean_token");
		free((*token)->prev->word);
		(*token)->prev->word = tmp;
		(*token)->word[0] = '\0';
	}
	if (!(*token)->word || !(*(*token)->word))
		return (token_remove(&(lex->tokens), *token));
	if (split && contains_space((*token)->word))
		return (split_words(token));
	return ((*token)->next);
}

static void	st_rm_tokenspace(t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->tokens;
	while (tmp)
	{
		if (tmp->flags & F_SPACE)
			tmp = token_remove(&(lexer->tokens), tmp);
		else
			tmp = tmp->next;
	}
}
