/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 12:05:50 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 12:20:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_env(char **envp)
{
	char	*output;
	int		i;

	i = 0;
	while (envp[i])
	{
		output = getenv(envp[i]);
		ft_putendl_fd(output, STDOUT_FILENO);
		// free(output);
		i++;
	}
}