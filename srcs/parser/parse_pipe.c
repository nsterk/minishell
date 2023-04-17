/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:59 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/17 17:13:56 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	s_add_redir(t_token **token, t_red **red, t_red_type type);

bool	parse_pipe(t_token **token, t_cmd **cmd)
{
	t_cmd	*current;

	current = cmd_last(*cmd);
	if (syntax_pipe(*cmd, *token))
		return (true);
	if (cmd_append(cmd, cmd_new()))
		exit_minishell(MALLOC_ERR);
	*token = (*token)->next;
	return (false);
}

bool	parse_redir(t_token **token, t_cmd *cmd)
{
	t_cmd	*current;

	if (!((*token)->next) || (*token)->next->type != TOK_WRD)
		return (error_msg("syntax error encountered in parse_redir"));
	current = cmd_last(cmd);
	if ((*token)->type == TOK_REDIR_IN && s_add_redir(token, &(current->in), RED_IPUT))
		exit_minishell(MALLOC_ERR);
		// exit_minishell(MALLOC_ERR, "Malloc failure in parse_redir (in)");
	if ((*token)->type == TOK_REDIR_OUT && s_add_redir(token, &(current->out), RED_OPUT))
		exit_minishell(MALLOC_ERR);
		// exit_minishell(MALLOC_ERR, "Malloc failure in parse_redir (out)");
	*token = (*token)->next;
	return (false);
}

static bool	s_add_redir(t_token **token, t_red **red, t_red_type type)
{
	t_red	*new;

	new = malloc(sizeof(t_red));
	if (!new)
		return (1);
	new->type = type;
	if (ft_strlen((*token)->word) == 2)
		new->type++;
	new->filename = ft_strdup((*token)->next->word);
	if (!new->filename)
		return (true);
	new->fd = -1;
	if (red_append(red, new))
		return (true);
	return (false);
}
