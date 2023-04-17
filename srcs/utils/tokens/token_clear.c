/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_clear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 16:19:08 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/01 20:54:16 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "utils.h"

void	tokenclear(t_token **token, void (*del)(void*))
{
	t_token	*tmp;

	if (!token)
		return ;
	while (*token)
	{
		tmp = (*token)->next;
		token_delone(*token, del);
		*token = tmp;
	}
}

void	cmdclear(t_cmd **cmd, void (*del)(void*))
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		cmd_delone(*cmd, del);
		*cmd = tmp;
	}
}

void	cmd_delone(t_cmd *cmd, void (*del)(void*))
{
	if (!cmd || !del)
		return ;
	if (cmd->args)
		ft_free_array(cmd->args); //! no check in ft_free_array before dereferencing str so check if that isnt a problem
	if (cmd->in)
		redclear(&cmd->in, del);
	if (cmd->out)
		redclear(&cmd->out, del);
	del(cmd);
}

void	redclear(t_red **red, void (*del)(void*))
{
	t_red	*tmp;

	if (!red)
		return ;
	while (*red)
	{
		tmp = (*red)->next;
		red_delone(*red, del);
		*red = tmp;
	}
}

void	red_delone(t_red *red, void (*del)(void*))
{
	if (!red || !del)
		return ;
	if (red->filename)
		del(red->filename);
	del(red);
}
