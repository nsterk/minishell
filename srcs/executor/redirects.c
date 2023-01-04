/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 11:53:25 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/04 15:06:10 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	st_file_error(const char *filename)
{
	if (!filename)
	{
		ft_putstr_fd("momoshell: ", STDERR_FILENO);
		ft_putendl_fd("ambiguous redirect", STDERR_FILENO);
		return (1);
	}
	ft_putstr_fd("momoshell: ", STDERR_FILENO);
	if (filename)
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd("No such file or directory", STDERR_FILENO);
	return (1);
}

static int	st_duplicate(int fd, int in_out_fileno, t_exec *exec)
{
	int	exit_status;

	if (dup2(fd, in_out_fileno) < 0)
	{
		perror(ft_itoa(errno)); // ! error check itoa
		exec->last_pid = errno;
		exit_status = EXIT_FAILURE;
	}
	exit_status = EXIT_SUCCESS;
	if (fd != 0 && fd != 1)
		close(fd);
	return (exit_status);
}

// TODO fix struct
int	redirect_in(t_io *input, int fd, t_exec *exec)
{
	while (input)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		if (input->type == RED_IPUT)
			fd = open(input->filename, O_RDONLY);
		else if (input->type == HERE_DOC)
			fd = input->heredoc;
		if (fd < 0)
			return (file_error(input->filename));
		input = input->next;
	}
	return (duplicate(fd, STDIN_FILENO, exec));
}

// TODO fix struct
int	redirect_out(t_io *output, int fd, t_exec *exec)
{
	int		flags;

	while (output)
	{
		if (fd != STDOUT_FILENO)
			close(fd);
		flags = O_CREAT | O_RDWR;
		if (output->type == RED_OPUT_A)
			flags = flags | O_APPEND;
		else
			flags = flags | O_TRUNC;
		fd = open(output->filename, flags, 0644);
		if (fd < 0)
			return (st_file_error(output->filename));
		output = output->next;
	}
	return (st_duplicate(fd, STDOUT_FILENO, exec));
}
