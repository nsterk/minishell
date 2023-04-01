/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/01 01:10:31 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		get_cmd_argc(t_token *token);
static t_token	*add_args(t_token **token, t_cmd *cmd);

t_token	*parse_args(t_token **token, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd_last(cmd);
	if (current->argc)
		exit_minishell(SYNTAX_ERR, "Syntax error: parse_args");
	current->argc = get_cmd_argc(*token);
	current->args = malloc(sizeof(char *) * (current->argc + 1));
	if (!current->args)
		exit_minishell(MALLOC_ERR, "Malloc failure in parse_args"); //! syntax error
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

static t_token	*add_args(t_token **token, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->argc)
	{
		cmd->args[i] = ft_strdup((*token)->word);
		if (!cmd->args[i])
			exit(EXIT_FAILURE); //!proper freeing of tha shit
		*token = (*token)->next;
		i++;
	}
	return (*token);
}
