/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/15 20:47:48 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "prompt.h"

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
	display_prompt();
	return (grab_input(lexer));
}

void	display_prompt(void)
{
	write(1, "$ ", 3);
}

int	grab_input(t_lexer *lexer)
{
	char	*raw_input;

	if (get_next_line(STDIN_FILENO, &raw_input) < 0)
		exit(1);
	if (!raw_input)
		return (1);
	lexer->input = ft_strtrim(raw_input, " \t\n\v\r\f");
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
