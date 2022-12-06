/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/06 17:40:42 by nsterk        ########   odam.nl         */
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
	lexer->str = grab_input(lexer, "momoshell-0.2$ ");
	if (!lexer->str)
		return (1);
	if (*lexer->str)
		add_history(lexer->str);
	return (1);
}

char	*grab_input(t_lexer *lexer, char *prompt)
{
	char	*line;

	line = readline(prompt);
	return (line);
}
