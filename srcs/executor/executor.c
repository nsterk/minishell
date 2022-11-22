/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:41:10 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 15:06:03 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	print_stuff(t_lexer *lexer)
{
	int		i;

	i = 0;
	while (lexer->tokens != NULL)
	{
		printf("%s\n", lexer->tokens[i].word);
		i++;
	}
}

static void	pipex_cmd()
{
	//
}

static void	simple_cmd(void)
{

	// redirection input => dup

	// redirection output => dup

	// builtin?

		// yes, exec builtin
		
		// no, exec cmd
}

// void	executor(t_lexer *lexer)
void	executor(char *cmd, char *option, const char *STRING, t_lexer *lexer) // ? testing
{
	// printf("\tInput executor: [ %s %s %s ]\n", cmd, option, STRING); // ? testing
	print_stuff(lexer);
	// if (!read_builtin(tokens->word))
	if (!read_builtin(cmd, option, STRING, lexer)) // ? testing
	{
		// printf("\tDetected builtin!\n");
	}

	// init heredoc

	// init paths

	// check if has next cmd
		
		// no, exec simple cmd

		// yes, exec pipex cmd

	// wait fork cmd

	// free paths
}
