/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:04:12 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/24 21:30:40 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*token_new(size_t start, size_t end, t_toktype type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->type = type;
	new->start = start;
	new->end = end;
	new->next = NULL;
	return (new);
}
