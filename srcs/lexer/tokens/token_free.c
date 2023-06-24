
#include "minishell.h"

static void	free_expansion(t_expansion *expansion, size_t i);

void	tokenclear(t_token **token, void (*del)(void*))
{
	t_token	*tmp;

	if (!token)
		return ;
	while (*token)
	{
		tmp = (*token)->next;
		token_delone(*token, del);
		*token = tmp;
	}
}

void	token_delone(t_token *token, void (*del)(void*))
{
	if (!token || !del)
		return ;
	if (token->word)
		del(token->word);
	if (token->exp)
		free_expansion(token->exp, token->exp_count);
	del(token);
}

static void	free_expansion(t_expansion *expansion, size_t i)
{
	while (i)
	{
		if (expansion[i - 1].param)
			free(expansion[i - 1].param);
		i--;
	}
	free(expansion);
}
