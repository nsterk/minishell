/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/02/13 21:20:52 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "test.h"

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
	print_tbl(*cmd);
	return ;
}
