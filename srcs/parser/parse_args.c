/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:26:47 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 18:06:54 by nsterk        ########   odam.nl         */
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
	current->argv = malloc(sizeof(char *) * (current->argc + 1));
	check_malloc(current->argv, "parse_args");
	current->argv[current->argc] = NULL;
	return (s_add_args(token, current));
}

static int	s_get_argc(t_token *token)
{
	size_t	i;
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
	int		i;

	i = 0;
	while (i < cmd->argc)
	{
		if ((*token)->flags & (F_WORD + F_SQUOTE + F_DQUOTE))
		{
			cmd->argv[i] = ft_strdup((*token)->word);
			check_malloc(cmd->argv[i], "s_add_args");
			i++;
		}
		*token = (*token)->next;
	}
	return (false);
}
