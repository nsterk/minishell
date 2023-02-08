/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/02/08 16:07:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TOK_CMD)
			tmp = parse_command(tmp, *cmd);
		else
			tmp = parse_pipe(tmp, *cmd);
	}
	// printf("parser works!\n");
	return ;
}
