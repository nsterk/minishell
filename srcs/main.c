/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/04/22 18:31:38 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

void	enter_shell(int argc, char **argv, char **envp)
{
	t_data	data;
	
	// ? to remove annoying errors
	if (argv)
		argc++;
	init_data(&data, envp);
	data.lexer.envp = envp;
	data.envp = envp;
	while (prompt(&data.lexer))
	{
		if (!lexer(&data.lexer))
		{
			if (!parser(data.lexer.tokens, &data.cmd))
			{
				g_state = EXECUTING;
				executor(&data, data.last_pid); // ? testing
			}
		}
		reinit_data(&data);
		write(STDOUT_FILENO, "\n", 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	enter_shell(argc, argv, envp);
	return (0);
}
