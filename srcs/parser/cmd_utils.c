
#include "minishell.h"

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argc = 0;
	cmd->args = NULL;
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
	if (cmd->args)
		ft_free_array(cmd->args); //! no check in ft_free_array before dereferencing str so check if that isnt a problem
	if (cmd->in)
		redclear(&cmd->in, del);
	if (cmd->out)
		redclear(&cmd->out, del);
	del(cmd);
}
