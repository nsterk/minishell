/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/12 14:49:22 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enter_shell(void)
{
	static char	*input;

	while (1)
	{
		// display_prompt();
		input = readline("$ ");
		if (!input)
			exit(EXIT_FAILURE);
		printf("Input: %s\n", input);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
