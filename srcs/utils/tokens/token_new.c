/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:04:12 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/09 20:55:35 by nsterk        ########   odam.nl         */
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

t_cmd	*cmd_new(char *str)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd = ft_strdup(str); //maybe allocating memory not needed here since original str (token->word) won't be freed until after executor is done
	if (!cmd->cmd)
		return (cmd_delone(cmd, free), NULL);
	return (cmd);
}
