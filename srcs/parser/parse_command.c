/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 20:31:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/13 15:29:21 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_cmd_argc(t_token *token);

t_token	*parse_command(t_token *token, t_cmd **cmd)
{
	t_cmd	*new;
	// int		i;

	new = cmd_new(token->word);
	if (!new)
		exit(EXIT_FAILURE); //! do proper error handling
	token = init_cmd(token, new, get_cmd_argc(token));
	
	if (cmd_append(cmd, new))
		exit(EXIT_FAILURE); //! error checking
	// i = 0;
	// while (i < new->argc)
	// {
	// 	new->args[i] = ft_strdup(token->word);
	// 	if (!new->args[i])
	// 		exit(EXIT_FAILURE); //!proper freeing of tha shit
	// 	token = token->next;
	// 	i++;
	// }
	// new->args[i] = NULL;
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
