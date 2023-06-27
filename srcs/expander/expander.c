
#include "minishell.h"

static t_token	*st_clean_token(t_lexer *lex, t_token **token);
static bool		st_handle_token(t_expander *expander, t_token *token);

bool	expander(t_expander *expander, t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->tokens;
	while (tmp)
	{
		if (st_handle_token(expander, tmp))
			return (true);
		tmp = st_clean_token(lexer, &(tmp));
	}
	if (lexer->tokens)
		rm_tokenspace(lexer);
	return (false);
}

bool	do_expanding(t_expander *expander, t_token *token)
{
	char		*env_val;
	size_t		new_len;

	get_param(expander, token);
	if (!ft_strncmp("?", expander->exp->param, 2))
		env_val = ft_itoa(*(expander->status));
	else
		env_val = ft_strdup(get_envp_value(expander->envp, \
			expander->exp->param));
	new_len = ft_strlen(env_val);
	token->word = ft_replace(token->word, env_val, expander->exp->start, \
		expander->exp->end);
	check_malloc(token->word, "do_expanding");
	expander->pos = expander->exp->start + new_len;
	return (false);
}

static t_token	*st_clean_token(t_lexer *lex, t_token **token)
{
	char	*tmp;
	bool	split;

	split = false;
	if ((*token)->flags ^ F_WORD)
		return ((*token)->next);
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
	if ((*token)->flags ^ F_FILENAME && (!(*token)->word || !(*(*token)->word)))
		return (token_remove(&(lex->tokens), *token));
	if (split && contains_space((*token)->word))
		return (split_words(token));
	return ((*token)->next);
}

static bool	st_handle_token(t_expander *expander, t_token *token)
{
	size_t		i;

	i = 0;
	expander->pos = 0;
	while (i < token->exp_count)
	{
		expander->exp = &(token->exp[i]);
		while (token->word[expander->pos])
		{
			if (token->word[expander->pos] == CH_EXPAND)
			{
				if (do_expanding(expander, token))
					return (true);
				break ;
			}
			expander->pos++;
		}
		i++;
	}
	return (false);
}
