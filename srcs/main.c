/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/11/15 15:12:29 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	print_tokens(t_token *tokens)
// {
// 	while (tokens->next != NULL)
// 	{
// 		printf("%s\n", tokens->word);
// 		tokens = tokens->next;
// 	}
// }

void	enter_shell(void)
{
	t_data	data;

	init_data(&data);
	while (prompt(&data.lexer))
	{
		lexer(&data.lexer);
		data.table = parser(data.tokens);
		init_lexer(&data.lexer);
		executor(data.lexer.tokens);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
