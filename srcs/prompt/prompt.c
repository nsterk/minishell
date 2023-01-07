/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/07 14:13:46 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>

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
	lexer->input = grab_input(lexer, "momoshell-0.4$ ");
	if (!lexer->input)
		return (1);
	if (*lexer->input)
		add_history(lexer->input);
	return (1);
}

char	*grab_input(t_lexer *lexer, char *prompt)
{
	char	*line;

	printf("%s\n", lexer->input);
	line = readline(prompt);
	return (line);
}
