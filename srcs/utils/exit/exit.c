/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 21:37:42 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/01 20:51:56 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exit_minishell(int status, char *msg)
{
	if (status == MALLOC_ERR)
		printf(RED"%s \n"RST, msg);
	if (status == SYNTAX_ERR)
		printf(BLU"%s \n"RST, msg);
	exit(status);
}

// bool	error_msg(char *msg)
// {
// 	if (msg)
// 		printf("%s\n", msg);
// 	return (true);
// }
