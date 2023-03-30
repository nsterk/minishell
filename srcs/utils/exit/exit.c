/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 21:37:42 by nsterk        #+#    #+#                 */
/*   Updated: 2023/03/30 18:31:36 by nsterk        ########   odam.nl         */
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
