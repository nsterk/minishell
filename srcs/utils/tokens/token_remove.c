/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_remove.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:50:34 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/29 19:34:22 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

/**
 * Add functions to remove single token
 * without compromising list structure 
 */

void	token_delone(t_token *token, void (*del)(void*))
{
	if (!token || !del)
		return ;
	del(token->word);
	free(token);
}

static t_token	*remove_head(t_token *head, t_token *token)
{
	head = head->next;
	head->prev = NULL;
	if (token->word)
		free(token->word);
	free(token);
	return (head);
}

static t_token	*remove_mid(t_token **head, t_token *token)
{
	token->next->prev = token->prev;
	token->prev->next = token->next;
	if (token->word)
		free(token->word);
	free(token);
	return (*head);
}

static t_token	*remove_tail(t_token **head, t_token *token)
{
	token->prev->next = NULL;
	if (token->word)
		free(token->word);
	free(token);
	return (*head);
}

t_token	*token_remove(t_token **head, t_token *token)
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