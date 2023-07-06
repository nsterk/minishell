/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:46:05 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/06 17:16:57 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_env(char **args, t_data *data)
{
	int		i;

	if (args[1])
		return (EXIT_FAILURE);
	i = 0;
	while (data->envp[i])
	{
		ft_putendl_fd(data->envp[i], STDOUT_FILENO);
		i++;
	}
	data->last_pid = 0;
	return (EXIT_SUCCESS);
}
