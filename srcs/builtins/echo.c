/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 10:37:54 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 11:18:13 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_echo(char *cmd, char *option, const char *STRING)
{
	char	*output;

	// Grab input (= str)
	if (!STRING)
	{
		output = "";
	}
	else
	{
		output = ft_strdup(STRING);
	}

	// Check if -n option
	if (!ft_strncmp(option, "-n", 3))
	{
		// output = "\n";
		output = ft_strjoin(output, "\n");
		if (!output)
		{
			return (EXIT_FAILURE);
		}
	}

	// Print input
	ft_putendl_fd(output, STDOUT_FILENO);
	free(output);
	return (EXIT_SUCCESS);
}
