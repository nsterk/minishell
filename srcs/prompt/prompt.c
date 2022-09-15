/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/15 20:23:13 by nsterk        ########   odam.nl         */
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
 * 
 * 
 */

//! I don't like that the function is called lexer and the data structuer
//! is also called lexer. Want to change this later.
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
		return (1); //TODO Handle empty input (user pressed enter on an empty prompt)
	lexer->input = ft_strtrim(raw_input, " \t\n\v\r\f");
	free(raw_input);
	if (!ft_strcmp(lexer->input, "exit"))
		return (free(lexer->input), 0);
	return (1);
}
