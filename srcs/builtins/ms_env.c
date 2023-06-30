/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:46:05 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:46:07 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_env(char **envp, t_data *data)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	data->last_pid = 0;
	return (EXIT_SUCCESS);
}
