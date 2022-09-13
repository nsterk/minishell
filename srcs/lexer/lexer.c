/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/13 03:14:57 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <get_next_line.h>
#include <pipex.h>

void	lexer(void)
{
	char	*input;

	input = readline("$ ");
	if (!input)
		exit(EXIT_FAILURE);
	printf("Input: %s\n", input);
	gen_tokens(input);
}

void	wait_for_children(t_pipex *pipex)
{
	int	i;
	int	status;

	if (pipex->here_doc)
		i = 1;
	else
		i = 0;
	while (i < pipex->nr_children)
	{
		waitpid(pipex->pid[i], &status, 0);
		if (WIFEXITED(status))
			pipex->status = WEXITSTATUS(status);
		i++;
	}
}

//need to trim whitespaces from the command before comparing to exit
void	lexern(void)
{
	int		ret;
	char	*input;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &input);
		if (!ft_strncmp(input, "exit", 100))
			exit(0);
	}
	if (!input)
		exit(EXIT_FAILURE);
	printf("Input: %s\n", input);
	gen_tokens(input);
	free(input);
	exit(0);
}
