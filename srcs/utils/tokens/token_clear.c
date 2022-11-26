/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_clear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:19:08 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/25 16:19:21 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	tokenclear(t_token **token, void (*del)(void*))
{
	t_token	*tmp;

	if (!token)
		return ;
	while (*token)
	{
		tmp = (*token)->next;
		token_delone(*token, del);
		*token = tmp;
	}
}
