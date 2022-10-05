/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:41:10 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/05 19:42:13 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	pipex_cmd()
{
	//
}

static void	simple_cmd(void)
{

	// redirection input => dup

	// redirection output => dup

	// builtin?

		// yes, exec builtin
		
		// no, exec cmd
}

void	executor(t_token *tokens)
{
	printf("\tInput executor: %s\n", tokens->word);
	
	if (!read_builtin(tokens->word))
		printf("\tDetected builtin!\n");

	// init heredoc

	// init paths

	// check if has next cmd
		
		// no, exec simple cmd

		// yes, exec pipex cmd

	// wait fork cmd

	// free paths
}
