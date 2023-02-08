/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 22:23:22 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/08 00:07:56 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_redirs(t_red *in, t_red *out);

// void	init_parser(t_cmd **cmd)
// {
// 	*cmd = malloc(sizeof(*cmd));
// 	if (!*cmd)
// 		exit(1); // exit correctly
// 	(*cmd)->cmd = NULL;
// 	(*cmd)->args = NULL;
// 	init_redirs(&(*cmd)->in, &(*cmd)->out);
// 	return ;
// }

void	init_cmd(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->args = NULL;
	init_redirs(&cmd->in, &cmd->out);
}

static void	init_redirs(t_red *in, t_red *out)
{
	in->type = DEFAULT;
	in->filename = NULL;
	in->fd = STDIN_FILENO;
	out->type = DEFAULT;
	out->filename = NULL;
	out->fd = STDOUT_FILENO;
}
