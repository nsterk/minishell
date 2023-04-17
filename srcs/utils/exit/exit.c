/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 21:37:42 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/17 16:52:40 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * Examples:
 * 	exit_error(3, "main", "malloc failure");
 * 		should output to standard error:
 * 			"main: malloc failure" 
 * 		or 
 * 	exit_error(errno, "main", NULL);
 * 		should output to standard error:
 * 			main: <errno message>
 * 	both functions exit with given exit code after displaying error message
*/
static void	st_write_msg(const char *fn, const char *msg)
{
	if (fn)
	{
		ft_putstr_fd(fn, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

/**
 * Exits program on error, and optionally displays an error message.
 * @param code 		Error code to exit with.
 * @param function	(optional) Function where the error was encountered.
 * @param message	(optional) Custom error message to display.
*/
void	exit_error(const int code, const char *function, const char *message)
{
	if (function || message)
		st_write_msg(function, message);
	exit(code);
}

void	exit_minishell(int status)
{
	//free input
	exit(status);
}

// bool	error_msg(char *msg)
// {
// 	if (msg)
// 		printf("%s\n", msg);
// 	return (true);
// }
