/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/08 16:30:49 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quick_lexer(t_lexer *lexer)
{
	char	**tokens;
	int		i;
	// int		ret;

	i = 0;
	tokens = ft_split(lexer->input, ' ');
	while (tokens[i] != NULL)
		i++;
	// ret = i;
	ft_free_array(tokens);
	return (i);
}

static int	quick_parser(t_lexer *lexer, int count)
{
	char	**tokens;
	int		i;

	i = 0;
	lexer->tokens = (t_token *)malloc(sizeof(t_token) * count);
	tokens = ft_split(lexer->input, ' ');
	while (tokens[i] != NULL)
	{
		lexer->tokens[i].word = tokens[i];
		// printf("token: %s\n", tokens[i]);
		// printf("parser: %s\n", lexer->tokens[i].word);
		i++;
	}
	return (i);
}

void	enter_shell(int argc, char **argv, char **envp)
{
	t_data	data;
	int		count;
	
	if (argv)
		argc++;
	init_data(&data, envp);
	data.lexer.envp = envp;
	while (prompt(&data.lexer))
	{
		// lexer(&data.lexer);
		count = quick_lexer(&data.lexer);
		quick_parser(&data.lexer, count);
		// data.table = parser(data.tokens);
		// init_lexer(&data.lexer);
		executor(&data.lexer); // ? testing

		/**
		 * ? Testing builtins
		*/
		// executor("echo", "", "", &data.lexer);
		// executor("echo", "-n", "", &data.lexer);
		// executor("echo", "-n", "test", &data.lexer);
		// executor("echo", "", "test", &data.lexer);
		// executor("echo", "-n", "hi\"\"\'string\'\"\"hi", &data.lexer);
		// executor("echo", "", "hi\"\"\'string\'\"\"hi", &data.lexer);
		// executor("pwd", "", "", &data.lexer);
		// executor("exit", "", "", &data.lexer);
		// executor("env", "", "", &data.lexer);

		// printf("\n"); // ? I think we need this after every cmd right?
	}
}

int	main(int argc, char **argv, char **envp)
{
	enter_shell(argc, argv, envp);
	return (0);
}
