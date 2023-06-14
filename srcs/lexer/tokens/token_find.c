
#include "minishell.h"

t_token	*token_first(t_token **token)
{
	t_token	*current;

	if (!token || !(*token))
		return (NULL);
	current = (*token);
	while (current->prev)
		current = current->prev;
	return (current);
}

t_token	*token_last(t_token *token)
{
	t_token	*current;

	if (!token)
		return (NULL);
	current = token;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
