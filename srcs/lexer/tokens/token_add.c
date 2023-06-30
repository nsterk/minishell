/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_add.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:23:38 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/28 18:23:40 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	token_append(t_token **token, t_token *new)
{
	t_token	*tail;

	if (!token || !new)
		return (true);
	if (*token == NULL)
		*token = new;
	else
	{
		tail = token_last(*token);
		new->prev = tail;
		tail->next = new;
	}
	return (false);
}

bool	token_addafter(t_token **spot, t_token *new)
{
	t_token	*next;

	if (!spot || !(*spot) || !new)
		return (true);
	next = (*spot)->next;
	new->prev = *spot;
	(*spot)->next = new;
	new->next = next;
	if (next)
		next->prev = new;
	return (false);
}
