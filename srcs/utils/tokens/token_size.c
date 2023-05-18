
#include "lexer.h"

int	token_size(t_token *token)
{
	int		i;

	i = 0;
	while (token)
	{
		token = token->next;
		i++;
	}
	return (i);
}
