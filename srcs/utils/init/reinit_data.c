/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reinit_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 18:15:40 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 18:15:41 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reinit_data(t_data *data)
{
	reinit_lexer(&data->lexer);
	cmdclear(&data->cmd, free);
	data->cmd = NULL;
	data->expander.exp = NULL;
	data->expander.envp = data->envp;
}

void	reinit_lexer(t_lexer *lexer)
{
	tokenclear(&lexer->tokens, free);
	lexer->tokens = NULL;
	if (lexer->str)
		free(lexer->str);
	lexer->str = NULL;
	lexer->expansions = 0;
	lexer->idx = 0;
	lexer->flags = 0;
}
