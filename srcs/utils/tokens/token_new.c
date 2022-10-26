/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:04:12 by nsterk        #+#    #+#                 */
/*   Updated: 2022/10/26 18:04:11 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*token_new(char *word, t_toktype type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->word = ft_strdup((const char *)word);
	if (!new->word)
		return (NULL);
	new->type = type;
	new->next = NULL;
	return (new);
}

t_token	*token_new2(size_t start, size_t end, t_toktype type)
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
