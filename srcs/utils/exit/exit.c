/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 21:37:42 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/07 15:09:13 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <utils.h>
#include "utils.h"

/*
	Exit function to use when something goes wrong.
	Can either be used with a custom error message or errno. 
	When used with errno, perror is used for error message.
	Arguments:
	(int)code:	
		error code to exit with
	(char *)func (nullable):	
		function where the error was encountered
	(char *)msg (nullable):	
		custom error message
	example:
	exit_error(3, "main", "malloc failure");
	should output to standard error:
	"main: malloc failure"
	or
	exit_error(errno, "main", NULL);
	should output to standard error:
	main: <errno message>
	both functions exit with given exit code after displaying error message
*/
static void	st_write_msg(const char *func, const char *msg)
{
	if (func)
	{
		ft_putstr_fd(func, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	exit_error(const int code, const char *func, const char *msg)
{
	if (func || msg)
		st_write_msg(func, msg);
	exit(code);
}

void	exit_minishell(int status)
{
	//free input
	exit(status);
}
