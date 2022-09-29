/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:04:12 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:43:33 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*token_new(char *word)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->word = ft_strdup((const char *)word);
	if (!new->word)
		return (NULL);
	new->next = NULL;
	return (new);
}
