/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/02/10 01:02:11 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;
	t_cmd	**tmp_cmd;

	tmp = token;
	tmp_cmd = cmd;
	while (tmp)
	{
		if (tmp->type == TOK_CMD)
		{
			tmp = parse_command(tmp, cmd);
		}
		else
		{
			tmp = parse_pipe(tmp, *cmd);
		}
	}
	while (*tmp_cmd)
	{
		printf("cmd->cmd: %s\ncmd->args: \n", (*tmp_cmd)->cmd);
		for (int i = 0; i <= (*tmp_cmd)->argc; i++)
			printf("%s\n", (*tmp_cmd)->args[i]);
		*tmp_cmd = (*tmp_cmd)->next;
	}
	return ;
}
