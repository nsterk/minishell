/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/11/22 15:04:00 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quick_parser(t_lexer *lexer)
{
	char	**tokens;
	int		i;

	i = 0;
	// printf("%s\n", lexer->input);
	tokens = ft_split(lexer->input, ' ');
	while (tokens[i] != NULL)
	{
		lexer->tokens->word = tokens[i];
		printf("%s\n", tokens[i]);
		i++;
	}
}

void	enter_shell(int argc, char **argv, char **envp)
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
		
		quick_parser(&data.lexer);

		/**
		 * ? Testing builtins
		*/
		executor("echo", "", "", &data.lexer);
		// executor("echo", "-n", "", &data.lexer);
		// executor("echo", "-n", "test", &data.lexer);
		// executor("echo", "", "test", &data.lexer);
		// executor("echo", "-n", "hi\"\"\'string\'\"\"hi", &data.lexer);
		// executor("echo", "", "hi\"\"\'string\'\"\"hi", &data.lexer);
		// executor("pwd", "", "", &data.lexer);
		// executor("exit", "", "", &data.lexer);
		// executor("env", "", "", &data.lexer);

		printf("\n"); // ? I think we need this after every cmd right?
	}
}

int	main(int argc, char **argv, char **envp)
{
	enter_shell(argc, argv, envp);
	return (0);
}
