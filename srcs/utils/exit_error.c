/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 12:12:50 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 12:13:12 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

void	write_custom_msg(const char *func, const char *msg)
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
		write_custom_msg(func, msg);
	exit(code);
}
