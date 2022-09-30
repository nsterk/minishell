/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_insert.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 17:36:40 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/29 17:18:16 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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