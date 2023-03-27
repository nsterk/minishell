/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/03/27 23:58:12 by nsterk        ########   odam.nl         */
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
		exit(EXIT_FAILURE); //! error handling
	while (tmp)
	{
		if (tmp->type == TOK_CMD)
		{
			tmp = parse_args(tmp, *cmd);
		}
		else if (tmp->type)
		{
			tmp = parse_pipe(tmp, cmd);
		}
	}
	print_tbl(*cmd);
	return ;
}

int	parse_error(void)
{
	// write the stupid motherfucking error and then free all the stupid shit and for that
	// i need to change the entire goddamn parser for what fucking data i'm feeding every function
	// and i want to fucking kill myself
}
