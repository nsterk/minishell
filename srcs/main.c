/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/04/22 15:38:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

void	enter_shell(int argc, char **argv, char **envp)
{
	t_data	data;
	// int		count;
	
	// ? to remove annoying errors
	if (argv)
		argc++;

	init_data(&data, envp);
	data.lexer.envp = envp;
	while (prompt(&data.lexer))
	{
		if (!lexer(&data.lexer))
		{
			token_printHtT(data.lexer.tokens);
			if (!parser(data.lexer.tokens, &data.cmd))
			{
				g_state = EXECUTING;
				executor(&data.lexer, data.last_pid); // ? testing
			}
		}
		reinit_data(&data);
		// printf("\n"); // ? I think we need this after every cmd right?
	}
}

int	main(int argc, char **argv, char **envp)
{
	enter_shell(argc, argv, envp);
	return (0);
}
