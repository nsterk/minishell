/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:59 by nsterk        #+#    #+#                 */
/*   Updated: 2023/03/31 19:02:22 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_redir(t_token *token, t_red **red, t_red_type type);

t_token	*parse_pipe(t_token *token, t_cmd **cmd)
{
	t_cmd	*current;

	current = cmd_last(*cmd);
	if (!current->argc || token->next == NULL || token->next->type == TOK_PIPE)
		exit_minishell(SYNTAX_ERR, "Syntax error: PIPE"); //! ERROR HANDLING
	if (cmd_append(cmd, cmd_new()))
		exit(EXIT_FAILURE);
	return (token->next);
}

t_token	*parse_redir(t_token *token, t_cmd *cmd)
{
	t_cmd	*current;

	if (!(token->next) || token->next->type != TOK_WRD)
		exit_minishell(SYNTAX_ERR, "Syntax error: REDIRECT"); //! ERROR HANDLING
	current = cmd_last(cmd);
	if (token->type == TOK_REDIR_IN && add_redir(token, &(current->in), RED_IPUT))
		exit_minishell(SYNTAX_ERR, "Malloc failure in parse_redir (in)"); //! ERROR HANDLING
	if (token->type == TOK_REDIR_OUT && add_redir(token, &(current->out), RED_OPUT))
		exit_minishell(SYNTAX_ERR, "Malloc failure in parse_redir (out)"); //! ERROR HANDLING
	return (token->next->next);
}

static int	add_redir(t_token *token, t_red **red, t_red_type type)
{
	t_red	*new;

	new = malloc(sizeof(t_red));
	if (!new)
		return (1);
	new->type = type;
	if (ft_strlen(token->word) == 2)
		new->type++;
	new->filename = ft_strdup(token->next->word);
	if (!new->filename)
		return (1);
	new->fd = -1; //initing fd to -1 and I don't know why but it feels like i have to init it at something and then a non-valid fd seems like the logical choice
	new->next = NULL;
	if (red_append(red, new))
		return (1);
	return (0);
}
