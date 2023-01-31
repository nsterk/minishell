/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:07:39 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/31 22:25:17 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>

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
