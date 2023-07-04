/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:18:51 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/02 11:51:55 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	st_parse_command(t_token **token, t_cmd **cmd);

bool	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	if (!token)
		return (true);
	tmp = token;
	*cmd = cmd_new();
	check_malloc(*cmd, "parser");
	while (tmp)
	{
		if (st_parse_command(&tmp, cmd))
			return (true);
	}
	return (false);
}

static bool	st_parse_command(t_token **token, t_cmd **cmd)
{
	if ((*token)->flags & F_WORD)
		return (parse_args(token, *cmd));
	if ((*token)->type == TOK_REDIR_IN || (*token)->type == TOK_REDIR_OUT)
		return (parse_redir(token, *cmd));
	if ((*token)->type == TOK_PIPE)
		return (parse_pipe(token, cmd));
	return (false);
}
