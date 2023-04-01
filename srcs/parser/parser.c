/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/04/01 01:05:15 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
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
		tmp = parse_command(&tmp, cmd);
	}
	print_tbl(*cmd);
	return (false);
}

t_token	*parse_command(t_token **token, t_cmd **cmd)
{
	if ((*token)->type == TOK_WRD)
		return (parse_args(token, *cmd));
	if ((*token)->type == TOK_REDIR_IN || (*token)->type == TOK_REDIR_OUT)
		return (parse_redir(token, *cmd));
	if ((*token)->type == TOK_PIPE)
		return (parse_pipe(token, cmd));
	return (NULL);
}

bool	syntax_error_msg(char *msg)
{
	printf("%s\n", msg);
	return (false);
}
