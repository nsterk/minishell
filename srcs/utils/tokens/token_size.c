/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:17:02 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:43:25 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	tokensize(t_token *token)
{
	int		i;

	i = 0;
	while (token)
	{
		token = token->next;
		i++;
	}
	return (i);
}
