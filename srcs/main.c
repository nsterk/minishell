/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/11/22 12:15:58 by abeznik       ########   odam.nl         */
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

void	enter_shell(char **envp)
{
	t_data	data;

	init_data(&data);
	data.lexer.envp = envp;
	while (prompt(&data.lexer))
	{
		lexer(&data.lexer);
		data.table = parser(data.tokens);
		// init_lexer(&data.lexer);
		// printf("%s", data.tokens->word);
		// executor(data.lexer.tokens);
		// executor(&data.lexer); // ? testing


		// executor("echo", "-n", "test"); // ? testing
		// executor("pwd", "", ""); // ? testing
		// executor("exit", "", ""); // ? testing
		executor("env", "", "", &data.lexer); // ? testing
	}
}

int	main(int argc, char **argv, char **envp)
{
	enter_shell(envp);
	return (0);
}
