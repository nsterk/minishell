/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/10/05 19:26:00 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_tokens(t_token *tokens)
{
	while (tokens->next != NULL)
	{
		printf("%s\n", tokens->word);
		tokens = tokens->next;
	}
}

void	enter_shell(void)
{
	t_data	data;

	while (prompt(&data.lexer))
	{
		lexer(&data.lexer);
		// print_tokens(data.lexer.tokens);
		// data.table = parser(data.tokens);
		executor(data.lexer.tokens);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
