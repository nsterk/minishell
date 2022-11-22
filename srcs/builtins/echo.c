/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 10:37:54 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 14:49:27 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_echo(char *cmd, char *option, const char *STRING)
{
	char	*output;

	// Print input
	// printf("cmd: %s\n", cmd);
	// printf("STRING: %s\n", STRING);

	// Grab input (= str)
	if (!STRING)
		output = "";
	else
		output = ft_strdup(STRING);

	// Check if -n option
	if (ft_strncmp(option, "-n", 3))
	{
		output = ft_strjoin(output, "\n");
		if (!output)
			return (EXIT_FAILURE);
	}

	// Print output
	ft_putstr_fd(output, STDOUT_FILENO);
	free(output);
	return (EXIT_SUCCESS);
}
