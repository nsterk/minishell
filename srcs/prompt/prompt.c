/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/09 15:21:04 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "prompt.h"
// #include <readline/readline.h>
// #include <readline/history.h>
// #include "signals.h"

/**
 * instead of while (1) can do while (prompt). prompt can return an int
 * depending on whether minishell needs to exit or not. Prompt will handle:
 * - display prompt
 * - grabbing the input
 * - sanitizing the input
 * - checking if exit command was called
 * - input->input can then be passed along to lexer to produce tokens.
 */

int	prompt(t_lexer *lexer)
{
	g_state = COMMAND;
	init_signals(); // ? testing
	lexer->input = grab_input("momoshell-0.5$ ");
	// printf("input: %s\n", lexer->input); // ? testing
	if (!lexer->input)
		exit(EXIT_SUCCESS);
	if (*lexer->input)
		add_history(lexer->input);
	return (1);
}

char	*grab_input(const char *PROMPT)
{
	char	*line;

	// init_signals(); // ? testing
	line = readline(PROMPT);
	return (line);
}
