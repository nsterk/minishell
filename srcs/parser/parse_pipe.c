/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:59 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/26 14:06:25 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
// #include "defines.h"
#include "parser.h"

static bool	st_add_redir(t_token **token, t_red **red, t_red_type type);

bool	parse_pipe(t_token **token, t_cmd **cmd)
{
	t_cmd	*current;

	current = cmd_last(*cmd);
	if (syntax_pipe(*token))
		return (true);
	if (cmd_append(cmd, cmd_new()))
		exit_minishell(MALLOC_ERR);
	*token = (*token)->next;
	return (false);
}

bool	parse_redir(t_token **token, t_cmd *cmd)
{
	t_cmd	*current;

	if (syntax_red(*token))
		return (true);
	current = cmd_last(cmd);
	if ((*token)->type == TOK_REDIR_IN && st_add_redir(token, &(current->in), RED_IPUT))
		exit_error(1, "parse_redir-in", "malloc failure");
	if ((*token)->type == TOK_REDIR_OUT && st_add_redir(token, &(current->out), RED_OPUT))
		exit_error(1, "parse_redir-out", "malloc failure");
	*token = (*token)->next;
	return (false);
}

static bool	st_add_redir(t_token **token, t_red **red, t_red_type type)
{
	t_red	*new;

	new = red_new(type);
	
	// malloc(sizeof(t_red));
	// check_malloc(new, "s_add_redir");
	// new->next = NULL;
	// new->type = type;
	if ((*token)->flags & F_APPEND)
		new->type++;
	if ((*token)->next->word && (*token)->next->word[0] != '\0')
	{
		new->filename = ft_strdup((*token)->next->word);
		check_malloc(new->filename, "st_add_redir");
	}
	(*token) = (*token)->next;
	// new->fd = -1;
	if (red_append(red, new))
		return (true);
	return (false);
}
