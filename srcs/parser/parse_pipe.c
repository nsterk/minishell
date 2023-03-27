/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:59 by nsterk        #+#    #+#                 */
/*   Updated: 2023/03/28 00:04:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*parse_pipe(t_token *token, t_cmd **cmd)
{
	t_cmd	*current;

	current = cmd_last(*cmd);
	if (!current->argc || token->next == NULL || token->next->type == TOK_PIPE)
		exit(EXIT_FAILURE); //! ERROR HANDLING: SYNTAX ERROR
	if (cmd_append(cmd, cmd_new()))
		exit(EXIT_FAILURE);
	return (token->next);
}
