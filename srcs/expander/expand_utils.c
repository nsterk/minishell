
#include "minishell.h"

// bool	do_expanding(t_token *token, t_expansion *exp, size_t *pos, char **envp)
// {
// 	char		*env_val;
// 	size_t		new_len;

// 	st_get_param(token, exp, pos);
// 	if (ft_strncmp("?", exp->parameter, 2))
// 		expand_exit_status();
// 	env_val = get_envp_value(envp, exp->parameter);
// 	new_len = ft_strlen(env_val);
// 	token->word = ft_replace(token->word, ft_strdup(env_val), exp->start, exp->end);
// 	check_malloc(token->word, "do_expanding");
// 	*pos = exp->start + new_len;
// 	return (false);
// }

void	rm_tokenspace(t_lexer *lexer)
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

bool	contains_space(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (len)
	{
		if (ft_isspace(str[len - 1]))
			return (true);
		len--;
	}
	return (false);
}

t_token	*clean_token(t_lexer *lex, t_token **token)
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

void	get_param(t_expander *expander, t_token *token)
{
	t_expansion *exp;
	size_t		*pos;

	exp = expander->exp;
	pos = &(expander->pos);
	exp->start = expander->pos;
	(*pos)++;
	if (ft_isdigit(token->word[*pos]) || token->word[*pos] == '?')
		exp->end = *pos;
	else
	{
		while (token->word[*pos] != CH_EXPAND && get_state(token->word[*pos]) == S_WORD)
			(*pos)++;
		exp->end = *pos - 1;
	}
	exp->parameter = ft_strndup(token->word + exp->start + 1, exp->end - exp->start);
	check_malloc(exp->parameter, "st_get_param");
}
