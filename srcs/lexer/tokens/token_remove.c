
#include "minishell.h"

/**
 * @brief remove the current token and set new current to previous token. well except for the first one or maye that one too i dontk now
 * 
 * @param head 
 * @param token 
 * @return t_token* 
 */

static t_token	*remove_head(t_token *head, t_token **token);
static t_token	*remove_mid(t_token **head, t_token **token);
static t_token	*remove_tail(t_token **head, t_token **token);

t_token	*token_remove(t_token **head, t_token **token)
{
	if (!token)
		return (NULL);
	if (!(token->prev) && token->next)
		return (remove_head(*head, token));
	if (token->prev && token->next)
		return (remove_mid(head, token));
	if (token->prev && !(token->next))
		return (remove_tail(head, token));
	return (NULL);
}

static t_token	*remove_head(t_token *head, t_token **token)
{
	head = head->next;
	head->prev = NULL;
	token_delone(token, free);
	return (head);
}

static t_token	*remove_mid(t_token **head, t_token **token)
{
	token->next->prev = token->prev;
	token->prev->next = token->next;
	token_delone(token, free);
	return (*head);
}

static t_token	*remove_tail(t_token **head, t_token **token)
{
	t_token	*tmp;

	tmp = (*token);
	*token = tmp->prev;
	token->prev->next = NULL;
	token_delone(token, free);
	return (*head);
}
