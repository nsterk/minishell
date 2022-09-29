/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_insert.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 17:36:40 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:37:47 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

//! this is really ugly and unoptimized but it works

int	token_addafter(t_token **spot, t_token *new)
{
	t_token	*prev;
	t_token	*next;

	if (!spot || !(*spot) || !new)
		return (1);
	next = (*spot)->next;
	prev = (*spot)->prev;
	new->prev = *spot;
	if ((*spot)->next == NULL)
	{
		(*spot)->next = new;
		return (0);
	}
	new->next = next;
	next->prev = new;
	prev->next = new;
	return (0);
}