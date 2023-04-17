/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/17 16:51:52 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	prompt(t_lexer *lexer)
{
	g_state = COMMAND;
	init_signals(); // ? testing
	// lexer->input = grab_input("momoshell-0.5 🐈 "); // ! :3
	// lexer->input = grab_input("momoshell-0.5$ ");
	lexer->str = readline("momoshell-0.5 🐈 ");
	// printf("input: %s\n", lexer->str); // ? testing
	if (!lexer->str)
		exit(EXIT_SUCCESS);
	if (*lexer->str)
		add_history(lexer->str);
	if (!lexer->str)
		return (1);
	return (1);
}
