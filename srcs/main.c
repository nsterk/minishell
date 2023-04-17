/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/04/17 16:44:55 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

/**
 * @brief Test lexer for executor testing
*/
// int	quick_lexer(t_lexer *lexer)
// {
// 	char	**tokens;
// 	int		i;

// 	i = 0;
// 	tokens = ft_split(lexer->input, ' ');
// 	if (!tokens)
// 		return (EXIT_FAILURE);
// 	while (tokens[i] != NULL)
// 		i++;
// 	ft_free_array(tokens);
// 	return (i);
// }

/**
 * @brief Test parser for executor testing
*/
// static int	quick_parser(t_lexer *lexer, int count)
// {
// 	char	**tokens;
// 	int		i;

// 	i = 0;
// 	lexer->tokens = (t_token *)malloc(sizeof(t_token) * count);
// 	if (!lexer->tokens)
// 		return (EXIT_FAILURE);
// 	tokens = ft_split(lexer->input, ' ');
// 	while (tokens[i] != NULL)
// 	{
// 		lexer->tokens[i].word = tokens[i];
// 		// printf("token: %s\n", tokens[i]); // ? testing
// 		// printf("parser: %s\n", lexer->tokens[i].word); // ? testing
// 		i++;
// 	}
// 	return (i);
// }

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
				printf("do executing \n");
		}
		// count = quick_lexer(&data.lexer); // ? testing
		// quick_parser(&data.lexer, count); // ? testing
		g_state = EXECUTING;
		executor(&data.lexer, data.last_pid); // ? testing
		reinit_data(&data);
		// printf("\n"); // ? I think we need this after every cmd right?
	}
}

int	main(int argc, char **argv, char **envp)
{
	enter_shell(argc, argv, envp);
	return (0);
}
