
#include "minishell.h"

/**
 * @brief remove the current node and return pointer to the previous node. Unless it's the head. Then it returns a ptr to the new head.
 * @param head 
 * @param token 
 * @return t_token* 
 */

static t_token	*remove_head(t_token **head, t_token **token);
static t_token	*remove_mid(t_token **head, t_token **token);
static t_token	*remove_tail(t_token **head, t_token **token);

t_token	*token_remove(t_token **head, t_token **token)
{
	if (!token || !(*token))
		return (NULL);
	if (!(*token)->prev && (*token)->next)
		return (remove_head(*head, token));
	if ((*token)->prev && (*token)->next)
		return (remove_mid(head, token));
	if ((*token)->prev && !(*token)->next)
		return (remove_tail(head, token));
	if (!(*token)->prev && !(*token)->next)
		write(1, "boe\n", 4);
	return (NULL);
}

static t_token	*remove_head(t_token **head, t_token **token)
{
	t_token	*tmp;
	tmp = (*token)->next;
	(*token)->next->prev = NULL;
	// *head = (*head)->next;
	// (*head)->prev = NULL;
	// (*)
	token_delone(*token, free);
	write(1, "you tried to remove the head and this is a problem\n", 52);
	return (*head);
}

static t_token	*remove_mid(t_token **head, t_token **token)
{
	t_token	*tmp;

	tmp = (*token)->prev;
	(*token)->next->prev = (*token)->prev;
	(*token)->prev->next = (*token)->next;
	token_delone(*token, free);
	return (tmp);
}

static t_token	*remove_tail(t_token **head, t_token **token)
{
	t_token	*tmp;

	tmp = (*token)->prev;
	(*token)->prev->next = NULL;
	token_delone(*token, free);
	return (tmp);
}
