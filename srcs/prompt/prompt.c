/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/22 14:49:11 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	prompt(t_lexer *lexer)
{
	g_state = COMMAND;
	init_signals(); // ? testing
	lexer->str = readline("momoshell-1.0 \U0001F408 ");
	// printf("input: %s\n", lexer->str); // ? testing
	if (!lexer->str)
		exit(EXIT_SUCCESS);
	if (*lexer->str)
		add_history(lexer->str);
	if (!lexer->str)
		return (1);
	return (1);
}
