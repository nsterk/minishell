/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/13 03:12:41 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <pipex.h>

void	lexern(void);

void	shell(void)
{
	while (1)
	{
		//display_prompt();
		lexern();
		//parser();
		// system("leaks minishell");
	}
}

void	enter_shell(void)
{
	int	status;
	int	pid;

//init stuff 
	pid = fork();
	if (pid == 0)
	{
		shell();
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);

}

int	main(void)
{
	enter_shell();
	return (0);
}
