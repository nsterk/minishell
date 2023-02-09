/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 22:23:22 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/09 21:00:44 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		init_redirs(t_red *in, t_red *out);
static t_token	*add_args(t_token *token, t_cmd *cmd);

t_token	*init_cmd(t_token *token, t_cmd *cmd, int argc)
{
	cmd->argc = argc;
	cmd->args = NULL;
	cmd->args = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!cmd->args)
		return (NULL);
	cmd->args[argc] = NULL;
	cmd->next = NULL;
	init_redirs(&cmd->in, &cmd->out);
	return (add_args(token, cmd));
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

static t_token	*add_args(t_token *token, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->argc)
	{
		cmd->args[i] = ft_strdup(token->word);
		if (!cmd->args[i])
			exit(EXIT_FAILURE); //!proper freeing of tha shit
		token = token->next;
		i++;
	}
	return (token);
}
