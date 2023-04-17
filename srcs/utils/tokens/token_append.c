/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_append.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:22 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/16 13:32:52 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"
#include "parser.h"

int	token_append(t_token **token, t_token *new)
{
	t_token	*tail;

	if (!token || !new)
		return (1);
	// write(1, new->word, ft_strlen(new->word));
	// fprintf(stderr, "new content: %s\n", new->word);
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

int	cmd_append(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*tail;

	if (!cmd || !new)
		return (1);
	if (*cmd == NULL)
		*cmd = new;
	else
	{
		tail = cmd_last(*cmd);
		tail->next = new;
	}
	return (0);
}

int	red_append(t_red **red, t_red *new)
{
	t_red	*tail;

	if (!red || !new)
		return (1);
	if (*red == NULL)
		*red = new;
	else
	{
		tail = red_last(*red);
		tail->next = new;
	}
	return (0);
}
