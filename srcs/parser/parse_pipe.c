/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pipe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:59 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/08 14:04:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*parse_pipe(t_token *token, t_cmd *cmd)
{
	if (token || cmd)
		printf("parse_pipe works!\n");
	return (token->next);
}
