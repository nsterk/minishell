/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 11:53:25 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 11:53:27 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

int	file_error(const char *filename)
{
	if (!filename)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putendl_fd("ambiguous redirect", STDERR_FILENO);
		return (1);
	}
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (filename)
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd("No such file or directory", STDERR_FILENO);
	return (1);
}

static int	duplicate(int fd, int in_out_fileno, t_mini_vars *vars)
{
	int	exit_status;

	if (dup2(fd, in_out_fileno) < 0)
	{
		perror(ft_itoa(errno));
		vars->last_pid = errno;
		exit_status = EXIT_FAILURE;
	}
	exit_status = EXIT_SUCCESS;
	if (fd != 0 && fd != 1)
		close(fd);
	return (exit_status);
}

int	redirect_input(t_red *input, int fd, t_mini_vars *vars)
{
	while (input)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		if (input->type == RED_IPUT)
			fd = open(input->file_name, O_RDONLY);
		else if (input->type == HERE_DOC)
			fd = input->heredoc;
		if (fd < 0)
			return (file_error(input->file_name));
		input = input->next;
	}
	return (duplicate(fd, STDIN_FILENO, vars));
}

int	redirect_output(t_red *output, int fd, t_mini_vars *vars)
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
		fd = open(output->file_name, flags, 0644);
		if (fd < 0)
			return (file_error(output->file_name));
		output = output->next;
	}
	return (duplicate(fd, STDOUT_FILENO, vars));
}
