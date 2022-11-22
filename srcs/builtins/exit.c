/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 11:46:53 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 12:01:25 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * exit [n] (unsigned decimal integer n)
 * 	Exits the shell with a status of N. If N is omitted, the exit status
 * 	is that of the last command executed
*/
int	exec_exit(void)
{
	exit(127);
	
	return (EXIT_SUCCESS);
}