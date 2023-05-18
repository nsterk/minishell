
#include "utils.h"
#include "lexer.h"

//! this is really ugly and unoptimized but it works

int	token_addafter(t_token **spot, t_token *new)
{
	t_token	*next;

	if (!spot || !(*spot) || !new)
		return (1);
	next = (*spot)->next;
	new->prev = *spot;
	(*spot)->next = new;
	new->next = next;
	next->prev = new;
	return (0);
}
