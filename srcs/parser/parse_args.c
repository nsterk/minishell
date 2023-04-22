/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/22 17:02:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	while (tmp && tmp->type == TOK_WRD)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static bool	s_add_args(t_token **token, t_cmd *cmd)
{
	int	i;

	i = 0;
	// cmd->cmd = ft_strdup()
	while (i < cmd->argc)
	{
		cmd->args[i] = ft_strdup((*token)->word);
		if (!cmd->args[i])
			exit_minishell(MALLOC_ERR);
		*token = (*token)->next;
		i++;
	}
	return (false);
}
