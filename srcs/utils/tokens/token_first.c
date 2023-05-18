
#include "lexer.h"
#include "utils.h"

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
