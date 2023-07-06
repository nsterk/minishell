/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:26:14 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/06 14:34:39 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	enter_shell(char **envp);
static bool	prompt(t_lexer *lexer);

void	check(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **envp)
{
	atexit(check);
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("momoshell: Incorrect usage: ./minishell", STDERR_FILENO);
		return (1);
	}
	enter_shell(envp);
	system("leaks -q minishell");
	return (0);
}

static void	enter_shell(char **envp)
{
	t_data	data;

	system("leaks -q minishell");
	init_data(&data, envp);
	system("leaks -q minishell");
	while (prompt(&data.lexer))
	{
		system("leaks -q minishell");
		if (!lexer(&data.lexer))
		{
			system("leaks -q minishell");
			expander(&data.expander, &data.lexer);
			system("leaks -q minishell");
			if (parser(data.lexer.tokens, &data.cmd))
			{
				system("leaks -q minishell");
				data.last_pid = 258;
			}
			else
			{
				system("leaks -q minishell");
				g_state = EXECUTING;
				executor(&data);
				system("leaks -q minishell");
			}
		}
		system("leaks -q minishell");
		reinit_data(&data);
	}
}

static bool	prompt(t_lexer *lexer)
{
	char	*tmp;

	g_state = COMMAND;
	tmp = NULL;
	system("leaks -q minishell");
	init_signals();
	system("leaks -q minishell");
	while (lexer->str == NULL || lexer->str[0] == '\0')
	{
		system("leaks -q minishell");
		tmp = readline("momoshell-3.0 🐈 ");
		system("leaks -q minishell");
		if (!tmp)
			exit(EXIT_SUCCESS);
		system("leaks -q minishell");
		if (lexer->str != NULL)
		{
			free(lexer->str);
			system("leaks -q minishell");
		}
		system("leaks -q minishell");
		lexer->str = ft_strdup(tmp);
		system("leaks -q minishell");
		if (!lexer->str)
		{
			system("leaks -q minishell");
			free(tmp);
			system("leaks -q minishell");
			exit(EXIT_SUCCESS);
		}
		free(tmp);
		system("leaks -q minishell");
		if (*lexer->str)
		{
			add_history(lexer->str);
			system("leaks -q minishell");
		}
		system("leaks -q minishell");
	}
	system("leaks -q minishell");
	return (true);
}
