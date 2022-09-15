/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/15 12:19:25 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enter_shell(void)
{
	while (1)
	{
		// lexer();
		parser();
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
