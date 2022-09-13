#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strndup(char *src, int n);
char	*ft_strgjoin(char *s1, char *s2, int len_s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#	endif