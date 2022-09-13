/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/13 17:10:24 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt()
{
	write(1, "$ ", 3);
}

void	enter_shell(void)
{
	while (1)
	{
		display_prompt();
		// char **tokens = lexer();
		// struct cmd_table = parser(tokens);
		// struct expanded_table = expander(cmd_table);
		// executor(expanded_table);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
