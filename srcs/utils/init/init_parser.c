
#include "parser.h"

static t_token	*add_args(t_token *token, t_cmd *cmd);

t_token	*init_cmd(t_token *token, t_cmd *cmd, int argc)
{
	cmd->argc = argc;
	cmd->args = NULL;
	cmd->args = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!cmd->args)
		return (NULL);
	cmd->args[argc] = NULL;
	cmd->next = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	return (add_args(token, cmd));
}

static t_token	*add_args(t_token *token, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->argc)
	{
		cmd->args[i] = ft_strdup(token->word);
		if (!cmd->args[i])
			exit(EXIT_FAILURE); //!proper freeing of tha shit
		token = token->next;
		i++;
	}
	return (token);
}
