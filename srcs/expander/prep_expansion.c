
#include "minishell.h"

static void	st_prep_token(t_token *token);

void	prep_expansion(t_lexer *lex)
{
	t_token	*tmp;

	tmp = lex->tokens;
	while (tmp)
	{
		st_prep_token(tmp);
		tmp = tmp->next;
	}
}

static void	st_prep_token(t_token *token)
{
	size_t	i;

	i = 0;
	while (i < token->exp_count)
	{
		printf("%zu\n", i);
		i++;
	}
}
