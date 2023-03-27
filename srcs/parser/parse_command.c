/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/14 18:28:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_cmd_argc(t_token *token);

t_token	*parse_command(t_token *token, t_cmd **cmd)
{
	t_cmd	*new;

	new = cmd_new(token->word);
	if (!new)
		exit(EXIT_FAILURE); //! do proper error handling
	token = init_cmd(token, new, get_cmd_argc(token));
	if (cmd_append(cmd, new))
		exit(EXIT_FAILURE); //! error checking
	return (token);
}

static int	get_cmd_argc(t_token *token)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = token;
	while (tmp && tmp->type == TOK_CMD)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
