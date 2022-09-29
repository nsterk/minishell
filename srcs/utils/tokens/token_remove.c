/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_remove.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:50:34 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 18:24:12 by nsterk        ########   odam.nl         */
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

static t_token	*remove_head(t_token *token)
{
	t_token	*new_head;

	new_head = token->next;
	new_head->prev = NULL;
	if (token->word)
		free(token->word);
	return (new_head);
}

static t_token	*remove_mid(t_token *token)
{
	return (token);
}

static t_token	*remove_tail(t_token *token)
{
	return (token);
}

t_token	*token_remove(t_token *token)
{
	if (!token)
		return (NULL);
	if (!(token->prev) && token->next)
		return (remove_head(token));
	if (token->prev && token->next)
		return (remove_mid(token));
	if (token->prev && !(token->next))
		return (remove_tail(token));
}
