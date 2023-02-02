/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/02/02 21:19:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	tmp = token;
	init_parser(cmd);
	while (tmp)
	{
		if (tmp->type != TOK_PIPE)
			tmp = parse_command(tmp, cmd);
		else
			tmp = parse_pipe(tmp, cmd);
	}
	// printf("parser works!\n");
	return ;
}
