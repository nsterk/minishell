/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 10:37:54 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/09 10:47:41 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// ? gives me another builtins.h on my mac
// #include "../../includes/builtins.h"

#include "stdlib.h"
#include "unistd.h"

/**
 * Executes the 'echo' builtin.
 * 	1.	- If input string is empty
 * 			=> output = empty
 * 		- Else
 * 			=> output = string
 * 	2. Check if -n option
 * 		- output = output + new line
 * 		- Check null output => return failure
 * 	3. Print output to standard output.
 * 	4. Free output.
 * 	5. Return success.
*/
int	exec_echo(char *cmd, char *option, const char *STRING)
{
	char	*output;

	// ? testing
	printf("cmd: %s\n", cmd);
	printf("option: %s\n", option);
	printf("STRING: %s\n", STRING);

	if (!STRING)
		output = "";
	else
		output = ft_strdup(STRING);
	if (ft_strncmp(option, "-n", 3))
	{
		output = ft_strjoin(output, "\n");
		if (!output)
			return (EXIT_FAILURE);
	}
	ft_putstr_fd(output, STDOUT_FILENO);
	free(output);
	return (EXIT_SUCCESS);
}
