/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/30 21:40:40 by nsterk        ########   odam.nl         */
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
	char	*raw_input;

	raw_input = grab_input(lexer, "momoshell-0.2$ ");
	if (!raw_input)
		return (1);
	if (*raw_input)
		add_history(raw_input);
	lexer->input = ft_strdup(raw_input); //! malloc protection
	free(raw_input);
	if (!ft_strcmp(lexer->input, "exit"))
		return (free(lexer->input), 0);
	lexer->words = ft_split((const char *)lexer->input, ' ');
	if (!lexer->words)
	{
		free(lexer->input);
		exit(EXIT_FAILURE);
	}
	return (1);
}

char	*grab_input(t_lexer *lexer, char *prompt)
{
	char	*line;
	char	*tmp;

	tmp = readline(prompt);
	if (tmp && *tmp && tmp[ft_strlen(tmp - 1)] == '\\')
		
	return (line);
}
