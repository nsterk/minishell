
#include "minishell.h"

static void	st_get_param(t_token *token, t_expansion *exp, size_t *pos);
// static char *st_env_not_found(t_token *token, size_t start, size_t end);


// OK so if token->word starts with a non-existing env var the 'front' part should not be allocated
// cause then the new word will be \0 instead of NULL and that's a --> problem <--

// NO it's not that we allocate and then put \0 there, it's that we increment pos and now it's pointing to the null terminator. so we need to delete the node.
// so do token_remove

bool	do_expanding(t_token *token, t_expansion *exp, size_t *pos, char **envp)
{
	char		*env_val;
	size_t		new_len;

	st_get_param(token, exp, pos);
	env_val = get_envp_value(envp, exp->parameter);
	new_len = ft_strlen(env_val);
	if (!new_len)
		token->word = ft_replace(token->word, ft_strdup(env_val), exp->start, exp->end);
	else
		token->word = ft_replace(token->word, NULL, exp->start, exp->end);
	*pos = exp->start + new_len;
	return (false);
}

static void	st_get_param(t_token *token, t_expansion *exp, size_t *pos)
{
	exp->start = *pos;
	(*pos)++;
	if (ft_isdigit(token->word[*pos]))
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

// static char *st_env_not_found(t_token *token, size_t start, size_t end)
// {

// }