/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/05/03 13:27:57 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"
#include <readline/readline.h>
#include <readline/history.h>

void	enter_shell(char **argv, char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	check_malloc(data, "enter_shell");
	init_data(data, envp);
	while (prompt(&data->lexer))
	{
		if (!lexer(&data->lexer))
		{
			if (!parser(data->lexer.tokens, &data->cmd))
			{
				g_state = EXECUTING;
				executor(&data, data->last_pid);
			}
		}
		reinit_data(&data);
	}
}

int	prompt(t_lexer *lexer)
{
	g_state = COMMAND;
	init_signals(); // ? testing
	while (lexer->str == NULL || lexer->str[0] == '\0')
	{
		lexer->str = readline("momoshell-1.0 🐈 ");
		if (!lexer->str)
			exit(EXIT_SUCCESS);
		if (*lexer->str)
			add_history(lexer->str);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc) 
		enter_shell(argv, envp);
	return (0);
}
