
#include "minishell.h"

static int		s_get_argc(t_token *token);
static bool		s_add_args(t_token **token, t_cmd *cmd);

bool	parse_args(t_token **token, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd_last(cmd);
	if (current->argc)
		return (error_msg("Syntax error encountered in parse_args"));
	current->argc = s_get_argc(*token);
	current->args = malloc(sizeof(char *) * (current->argc + 1));
	if (!current->args)
		exit_minishell(MALLOC_ERR);
	current->args[current->argc] = NULL;
	return (s_add_args(token, current));
}

static int	s_get_argc(t_token *token)
{
	int		i;
	t_token	*tmp;


	i = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->flags & (F_WORD + F_SQUOTE + F_DQUOTE))
			i++;
		else if (tmp->flags & F_OPERATOR)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

static bool	s_add_args(t_token **token, t_cmd *cmd)
{
	int	i;
	int	flags;

	i = 0;
	while (i < cmd->argc)
	{
		flags = (*token)->flags;
		if (flags & (F_WORD + F_SQUOTE + F_DQUOTE))
		{
			cmd->args[i] = ft_strdup((*token)->word);
			if (!cmd->args[i])
				exit_minishell(MALLOC_ERR);
			i++;
		}
		*token = (*token)->next;
	}
	return (false);
}
