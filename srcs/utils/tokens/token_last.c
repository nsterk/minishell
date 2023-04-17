/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_last.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:51 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/16 13:31:06 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"
#include "parser.h"

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

t_cmd	*cmd_last(t_cmd	*cmd)
{
	t_cmd	*current;

	if (!cmd)
		return (NULL);
	current = cmd;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_red	*red_last(t_red	*red)
{
	t_red	*current;

	if (!red)
		return (NULL);
	current = red;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
