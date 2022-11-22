/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:41:10 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 12:16:26 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

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

void	test(char *input, t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	while (tmp)
	{
		write(STDOUT_FILENO, input + tmp->start, tmp->end - tmp->start + 1);
		write(STDOUT_FILENO, " - ", 3);
		// printf("type: %d word: %s - ", tmp->type, tmp->word);
		tmp = tmp->next;
	}
	printf("\n");
}

// void	executor(t_lexer *lexer)
void	executor(char *cmd, char *option, const char *STRING, t_lexer *lexer) // ? testing
{
	printf("\tInput executor: [ %s %s %s ]\n", cmd, option, STRING); // ? testing
	// test(lexer->input, lexer->tokens);
	
	// if (!read_builtin(tokens->word))
	if (!read_builtin(cmd, option, STRING, lexer)) // ? testing
		printf("\tDetected builtin!\n");

	// init heredoc

	// init paths

	// check if has next cmd
		
		// no, exec simple cmd

		// yes, exec pipex cmd

	// wait fork cmd

	// free paths
}
