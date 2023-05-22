
#include "executor.h"

int	file_error(const char *filename)
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

static int	st_duplicate(int fd, int in_out_fileno, t_data_exe *data_exe)
{
	int	exit_status;

	if (dup2(fd, in_out_fileno) < 0)
	{
		perror(ft_itoa(errno)); // ! error check itoa
		data_exe->last_pid = errno;
		exit_status = EXIT_FAILURE;
	}
	exit_status = EXIT_SUCCESS;
	if (fd != 0 && fd != 1)
		close(fd);
	return (exit_status);
}

int	redirect_in(t_red *input, int fd, t_data_exe *data_exe)
{
	while (input)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		if (input->type == RED_IPUT)
			fd = open(input->filename, O_RDONLY);
		else if (input->type == HERE_DOC)
			fd = input->fd;
		if (fd < 0)
			return (file_error(input->filename));
		input = input->next;
	}
	return (st_duplicate(fd, STDIN_FILENO, data_exe));
}

int	redirect_out(t_red *output, int fd, t_data_exe *data_exe)
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
			return (file_error(output->filename));
		output = output->next;
	}
	return (st_duplicate(fd, STDOUT_FILENO, data_exe));
}
