/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 11:52:56 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 11:53:31 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	delim_in_line(char *line, char *delim, int len)
{
	if (!ft_strncmp(line, delim, len))
	{
		if (line[len] == '\n' && line[len + 1] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

static char	*get_text(char *delim)
{
	char	*line;
	char	*text;
	int		len;

	text = NULL;
	len = ft_strlen(delim);
	while (true)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (delim_in_line(line, delim, len))
		{
			free(line);
			break ;
		}
		text = ft_strjoin_free(text, line);
	}
	return (text);
}

static void	child_process(int end[2], char *delim)
{
	char	*text;

	signal(SIGINT, SIG_DFL);
	text = get_text(delim);
	ft_putstr_fd(text, end[WRITE]);
	free(text);
	close(end[WRITE]);
	exit(EXIT_SUCCESS);
}

int	here_doc(char *delim)
{
	int		end[2];
	int		pid;
	int		status;

	if (pipe(end) < 0)
		exit_error(errno, "here_doc", NULL);
	g_state = HEREDOC_INPUT;
	pid = fork();
	if (pid < 0)
		exit_error(errno, "here_doc", NULL);
	else if (pid == CHILD)
		child_process(end, delim);
	close(end[WRITE]);
	waitpid(pid, &status, 0);
	g_state = EXECUTING;
	if (WIFSIGNALED(status))
	{
		close(end[READ]);
		return (-1);
	}
	return (end[READ]);
}
