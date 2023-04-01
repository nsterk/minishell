/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/01 20:51:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		get_cmd_argc(t_token *token);
static bool		add_args(t_token **token, t_cmd *cmd);

bool	parse_args(t_token **token, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd_last(cmd);
	if (current->argc)
		return (error_msg("Syntax error encountered in parse_args"));
	current->argc = get_cmd_argc(*token);
	current->args = malloc(sizeof(char *) * (current->argc + 1));
	if (!current->args)
		exit_minishell(MALLOC_ERR, "Malloc failure in parse_args");
	current->args[current->argc] = NULL;
	return (add_args(token, current));
}

static int	get_cmd_argc(t_token *token)
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

static bool	add_args(t_token **token, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->argc)
	{
		cmd->args[i] = ft_strdup((*token)->word);
		if (!cmd->args[i])
			exit_minishell(MALLOC_ERR, "Malloc failure in add_args");
		*token = (*token)->next;
		i++;
	}
	return (false);
}
