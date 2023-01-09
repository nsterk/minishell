/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 10:37:54 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/08 16:47:43 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "builtins.h"
#include "../../includes/builtins.h"

#include "stdlib.h"
#include "unistd.h"

int	exec_echo(char *cmd, char *option, const char *STRING)
{
	char	*output;

	// Print input
	printf("cmd: %s\n", cmd);
	printf("option: %s\n", option);
	printf("STRING: %s\n", STRING);

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
