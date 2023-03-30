/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/03/30 20:33:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "test.h"

void	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	tmp = token;
	*cmd = cmd_new();
	if (!(*cmd))
		exit_minishell(MALLOC_ERR, "Malloc failure in parser");
	while (tmp)
	{
		tmp = parse_command(tmp, cmd);
	}
	print_tbl(*cmd);
	return ;
}

t_token	*parse_command(t_token *token, t_cmd **cmd)
{
	if (token->type == TOK_CMD)
		return (parse_args(token, *cmd));
	if (token->type == TOK_REDIR_IN || token->type == TOK_REDIR_OUT)
		return (parse_redir(token, *cmd));
	if (token->type == TOK_PIPE)
		return (parse_pipe(token, cmd));
	return (NULL);
}

int	parse_error(void)
{
	return (0);
}
