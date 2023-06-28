/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:26:26 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/28 18:26:27 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argc = 0;
	cmd->argv = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->next = NULL;
	return (cmd);
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

bool	cmd_append(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*tail;

	if (!cmd || !new)
		return (true);
	if (*cmd == NULL)
		*cmd = new;
	else
	{
		tail = cmd_last(*cmd);
		tail->next = new;
	}
	return (false);
}

void	cmdclear(t_cmd **cmd, void (*del)(void*))
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		cmd_delone(*cmd, del);
		*cmd = tmp;
	}
}

void	cmd_delone(t_cmd *cmd, void (*del)(void*))
{
	if (!cmd || !del)
		return ;
	if (cmd->argv)
		ft_free_array(cmd->argv);
	if (cmd->in)
		redclear(&cmd->in, del);
	if (cmd->out)
		redclear(&cmd->out, del);
	del(cmd);
}
