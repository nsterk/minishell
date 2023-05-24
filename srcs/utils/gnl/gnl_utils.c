
#include "utils.h"

int	check_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (0);
		line++;
	}
	return (1);
}

void	change_buffer(char *buffer, int buffer_size)
{
	int		i;

	i = 0;
	while (buffer_size < BUFFER_SIZE)
	{
		buffer[i] = buffer[buffer_size];
		buffer_size++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

void	make_newline(char *new_line, char *line, char *buffer, int buffer_size)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (j < buffer_size)
	{
		new_line[i] = buffer[j];
		i++;
		j++;
	}
	new_line[i] = '\0';
	return ;
}

char	*add_buffer(char *line, char *buffer, int buffer_size, int size_line)
{
	char	*new_line;

	new_line = (char *)malloc(size_line + 1);
	check_malloc(new_line, "add_buffer");
	make_newline(new_line, line, buffer, buffer_size);
	change_buffer(buffer, buffer_size);
	free(line);
	return (new_line);
}

int	check_buffer(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
			return (i + 1);
		else if (buffer[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}
