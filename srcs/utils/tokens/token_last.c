
#include "utils.h"
#include "lexer.h"
#include "parser.h"

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

t_cmd	*cmd_last(t_cmd	*cmd)
{
	t_cmd	*current;

	if (!cmd)
		return (NULL);
	current = cmd;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_red	*red_last(t_red	*red)
{
	t_red	*current;

	if (!red)
		return (NULL);
	current = red;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
