
#include "utils.h"

static char	*st_get_line(char *line, int fd, char *buffer)
{
	int			size_line;
	int			buffer_size;

	size_line = 0;
	buffer_size = check_buffer(buffer);
	size_line += buffer_size;
	line = add_buffer(line, buffer, buffer_size, size_line);
	if (!check_line(line))
		return (line);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		buffer_size = check_buffer(buffer);
		size_line += buffer_size;
		line = add_buffer(line, buffer, buffer_size, size_line);
		if (!check_line(line))
			break ;
	}
	return (line);
}

char	*gnl(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > 1024 || read(fd, buffer, 0) == -1)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	check_malloc(line, "get_next_line");
	line[0] = '\0';
	line = st_get_line(line, fd, buffer);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
