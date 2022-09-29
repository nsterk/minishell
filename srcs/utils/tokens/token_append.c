/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_append.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:22 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:48:40 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

int	token_append(t_token **token, t_token *new)
{
	t_token	*tail;

	if (!token || !new)
		return (1);
	if (*token == NULL)
		*token = new;
	else
	{
		tail = token_last(*token);
		new->prev = tail;
		tail->next = new;
	}
	return (0);
}
