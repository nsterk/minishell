/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/31 22:22:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
simple_command	:	cmd_prefix	cmd_word	cmd_suffix
				|	cmd_prefix	cmd_word
				|   cmd_prefix
				|   cmd_name    cmd_suffix
				|   cmd_name

cmd_prefix      :				io_redirect

 */

t_table	*parser(t_token *token)
{
	t_table	*table = NULL;
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TOK_PIPE)
			parse_pipe(token, table);
		else
			parse_command(token, table);
		tmp = tmp->next;
	}
	// printf("parser works!\n");
	return (table);
}
