/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/04/01 21:17:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

bool	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	tmp = token;
	*cmd = cmd_new();
	if (!(*cmd))
		exit_minishell(MALLOC_ERR, "Malloc failure in parser");
	while (tmp)
	{
		if (parse_command(&tmp, cmd))
			return (true);
	}
	print_tbl(*cmd);
	return (false);
}

bool	parse_command(t_token **token, t_cmd **cmd)
{
	if ((*token)->type == TOK_WRD)
		return (parse_args(token, *cmd));
	if ((*token)->type == TOK_REDIR_IN || (*token)->type == TOK_REDIR_OUT)
		return (parse_redir(token, *cmd));
	if ((*token)->type == TOK_PIPE)
		return (parse_pipe(token, cmd));
	return (false);
}

bool	error_msg(char *msg)
{
	printf("momoshell: %s\n", msg);
	return (true);
}
