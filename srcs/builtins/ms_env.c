/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 12:05:50 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/22 09:33:59 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "builtins.h"
#include "../../includes/builtins.h" // ? I need this on my mac

int	exec_env(char **envp, t_data_exe *data_exe)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	data_exe->last_pid = 0;
	return (EXIT_SUCCESS);
}