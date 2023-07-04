/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:26:14 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/04 12:52:26 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	enter_shell(char **envp);
static bool	prompt(t_lexer *lexer);

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("momoshell: Incorrect usage: ./minishell", STDERR_FILENO);
		return (1);
	}
	enter_shell(envp);
	return (0);
}

static void	enter_shell(char **envp)
{
	t_data	data;

	init_data(&data, envp);
	while (prompt(&data.lexer))
	{
		if (!lexer(&data.lexer))
		{
			expander(&data.expander, &data.lexer);
			if (parser(data.lexer.tokens, &data.cmd))
				data.last_pid = 258;
			else
			{
				g_state = EXECUTING;
				executor(&data);
			}
		}
		reinit_data(&data);
	}
}

static bool	prompt(t_lexer *lexer)
{
	g_state = COMMAND;
	init_signals();
	while (lexer->str == NULL || lexer->str[0] == '\0')
	{
		lexer->str = readline("momoshell-2.0 🐈 ");
		if (!lexer->str)
			exit(EXIT_SUCCESS);
		if (*lexer->str)
			add_history(lexer->str);
	}
	return (true);
}
