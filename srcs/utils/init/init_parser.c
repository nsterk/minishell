/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 22:23:22 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/02 21:27:54 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_redirs(t_red *in, t_red *out);

void	init_parser(t_cmd **cmd)
{
	*cmd = malloc(sizeof(*cmd));
	if (!*cmd)
		exit(1); // exit correctly
	(*cmd)->exec.cmd = NULL;
	(*cmd)->exec.args = NULL;
	(*cmd)->exec.argc = 0;
	init_redirs(&(*cmd)->in, &(*cmd)->out);
	return ;
}

static void	init_redirs(t_red *in, t_red *out)
{
	in->type = DEFAULT;
	in->filename = NULL;
}
