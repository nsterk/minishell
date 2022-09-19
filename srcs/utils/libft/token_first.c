/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_first.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 20:06:00 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/19 20:08:08 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

t_token	*token_first(t_token *token)
{
	t_token	*current;

	if (!token)
		return (NULL);
	current = token;
	while (current->prev)
		current = current->prev;
	return (current);
}
