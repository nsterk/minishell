/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/26 01:32:04 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/13 01:07:22 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <get_next_line.h>
#include <fcntl.h>
#include <stdio.h>

/*
	We can have a version of this be our prompt. We want to read from the command
	line until we encounter "exit". But then inside that loop instead of
	writing to fd1 we process the input from the command line and display the output
	(or if there's no output on the terminal just the prompt).

	I wrote the most pseudocode ever below the original function.
*/
int	read_from_cmdl(char *delimiter)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("tmp_here_doc", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd1 == -1)
	{
		printf("\e[0;31merror: failed to open file\e[0m\n");
		return (-1);
	}
	while (get_next_line(STDIN_FILENO, &line) > 0 && ft_strncmp(line, delimiter, 100)) //no idea why i have strncnp with n of 100. probably result of wanting to finish the project and issues with gnl or something
	{
		write(fd1, line, ft_strglen(line));
		write(fd1, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	fd2 = open("tmp_here_doc", O_RDONLY, 0777);
	close(fd1);
	return (fd2);
}

int	prompt(void)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0 && ft_strncmp(line, "exit", 100))
	{
		//process input (lexer, parser, expander, executor)
		//display prompt + output
		free(line);
	}
	if (line)
		free(line);
	return (0);
}