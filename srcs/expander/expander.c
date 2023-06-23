
#include "minishell.h"

// static t_token	*st_clean_token(t_lexer *lexer, t_token **token);
static bool		st_handle_token(t_expander *expander, t_token *token);

bool	expander(t_expander *expander, t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->tokens;
	while (tmp)
	{
		if (st_handle_token(expander, tmp))
			return (true);
		tmp = clean_token(lexer, &(tmp));
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
	if (!ft_strncmp("?", expander->exp->parameter, 2))
		env_val= ft_itoa(*(expander->status));
	else
		env_val = ft_strdup(get_envp_value(expander->envp, expander->exp->parameter));
	check_malloc(env_val, "do_expanding");
	new_len = ft_strlen(env_val);
	token->word = ft_replace(token->word, env_val, expander->exp->start, \
		expander->exp->end);
	check_malloc(token->word, "do_expanding");
	expander->pos = expander->exp->start + new_len;
	return (false);
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
