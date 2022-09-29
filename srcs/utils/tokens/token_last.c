/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_last.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:51 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:34:02 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

t_token	*token_last(t_token *token)
{
	t_token	*current;

	if (!token)
		return (NULL);
	current = token;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
