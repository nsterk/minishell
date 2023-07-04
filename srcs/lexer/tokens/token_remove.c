/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_remove.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:24:11 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/02 14:39:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief remove the current node and return pointer to the next node.
 * @param head 
 * @param token 
 * @return t_token* 
 */

static t_token	*remove_head(t_token **head, t_token *token);
static t_token	*remove_mid(t_token *token);
static t_token	*remove_tail(t_token *token);

t_token	*token_remove(t_token **head, t_token *token)
{
	if (!token || !(*head))
		return (NULL);
	if (!token->prev)
		return (remove_head(head, token));
	if (token->prev && token->next)
		return (remove_mid(token));
	if (token->prev && !token->next)
		return (remove_tail(token));
	return (NULL);
}

static t_token	*remove_head(t_token **head, t_token *token)
{
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	token_delone(token, free);
	return (*head);
}

static t_token	*remove_mid(t_token *token)
{
	t_token	*tmp;

	tmp = token->next;
	tmp->prev = token->prev;
	tmp->prev->next = tmp;
	token_delone(token, free);
	return (tmp);
}

static t_token	*remove_tail(t_token *token)
{
	t_token	*tmp;

	tmp = token->next;
	token->prev->next = NULL;
	token_delone(token, free);
	return (tmp);
}
