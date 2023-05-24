
#include "executor.h"

static int	st_delim_in_line(char *line, char *delim, int len)
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

/**
 * Gets the text based on the delimiter.
 * 	Loop:
 * 		1. Display "> ".
 * 		2. Get user input line.
 * 		3. If delimiter in line:
 * 			- free line, and
 * 			- break out of loop.
 * 		4. Append line to saved text.
 * 	Return text.
*/
static char	*st_get_text(char *delim)
{
	char	*line;
	char	*text;
	int		len;

	text = NULL;
	len = ft_strlen(delim);
	while (true)
	{
		ft_putstr_fd("> ", 2);
		line = gnl(STDIN_FILENO);
		if (st_delim_in_line(line, delim, len))
		{
			free(line);
			break ;
		}
		text = strjoin_free(text, line);
	}
	return (text);
}

/**
 * Handles the child process.
 * 	1. Signal
 * 	2. Get text delimeter.
 * 	3. Write text to write pipe end (= input of next pipe).
 * 	4. Free text.
 * 	5. Close write pipe end.
 * 	6. Exit success.
*/
static void	st_child_process(int pend[2], char *delim)
{
	char	*text;

	signal(SIGINT, SIG_DFL);
	text = st_get_text(delim);
	ft_putstr_fd(text, pend[WRITE]);
	free(text);
	close(pend[WRITE]);
	exit(EXIT_SUCCESS);
}

/**
 * Executes here_doc.
 * 	1. Check pipe error.
 * 	2. Set state global variable to here_doc input.
 * 	3. Fork process.
 * 	4. Check fork error:
 * 		- < 0 => exit error.
 * 		- = 0 (child) => handle child process.
 * 	5. Close write end of pipe.
 * 	6. Wait for current process.
 * 	7. Set state global variable to executing.
 * 	8. If process raised a signal (exited abnormally):
 * 		- close read end of pipe, and
 * 		- return -1.
 * 	9. Return read pipe end.
*/
int	here_doc(char *delim)
{
	int		pend[2];
	int		pid;
	int		status;

	if (pipe(pend) < 0)
		exit_error(errno, "here_doc pipe", NULL);
	g_state = HEREDOC_INPUT;
	pid = fork();
	if (pid < 0)
		exit_error(errno, "here_doc fork", NULL);
	else if (pid == CHILD)
		st_child_process(pend, delim);
	close(pend[WRITE]);
	waitpid(pid, &status, 0);
	g_state = EXECUTING;
	if (WIFSIGNALED(status))
	{
		close(pend[READ]);
		return (-1);
	}
	return (pend[READ]);
}
