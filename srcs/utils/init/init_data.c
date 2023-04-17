/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 18:02:52 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/17 16:43:54 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char **envp)
{
	init_lexer(&data->lexer);
	data->lexer.envp = envp;
	data->last_pid = 0; // ! important
	data->cmd = NULL;
}

void	reinit_data(t_data *data)
{
	reinit_lexer(&data->lexer);
	cmdclear(&data->cmd, free);
	data->cmd = NULL;
}
