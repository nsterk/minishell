/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/02 21:15:52 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*parse_command(t_token *tmp_token, t_cmd *cmd)
{
	if (cmd || tmp_token)
		printf("parse_command works!\n");
	return (tmp_token->next);
}
