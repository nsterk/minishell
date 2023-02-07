/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:04:12 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/07 20:37:50 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

t_token	*token_new(t_toktype type, t_lexstate state, char *str)
{
	t_token	*new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->word = str;
	new->type = type;
	new->state = state;
	return (new);
}

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	init_cmd(cmd);
	return (cmd);
}
