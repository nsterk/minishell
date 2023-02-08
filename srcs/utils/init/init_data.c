/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 18:02:52 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/08 13:59:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data)
{
	init_lexer(&data->lexer);
	data->cmd = NULL;
}

void	reinit_data(t_data *data)
{
	reinit_lexer(&data->lexer);
	cmdclear(&data->cmd, free);
	data->cmd = NULL;
}
