
#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>

typedef enum e_status
{
	SUCCESS,
	MALLOC_ERR,
	SYNTAX_ERR
}	t_status;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Exit functions.
 */
void			exit_minishell(int status);
void			exit_error(const int code, const char *func, const char *msg);

/**
 * Needed by executor.
*/
void			check_malloc(void *ptr, char *func);
char			*strjoin_free(char *s1, char *s2);
char			*gnl(int fd);
int				check_buffer(char *buffer);
char			*add_buffer(char *line, char *buffer, int buffer_size, int size_line);
void			make_newline(char *new_line, char *line, char *buffer, int buffer_size);
void			change_buffer(char *buffer, int buffer_size);
int				check_line(char *line);

/**
 * Libft functions.
 */
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_itoa(int n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
// void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
// void				*ft_memchr(const void *s, int c, size_t n);
// int					ft_memcmp(const void *s1, const void *s2, size_t n);
// void				*ft_memmove(void *dst, const void *src, size_t len);
// void				*ft_memset(void *str, int c, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *src);
char				*ft_strndup(char *src, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_isspace(int c);
char				*ft_strjoin(char const *s1, char const *s2);
// size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, char *src);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
// int					ft_strcmp(char *s1, char *s2);
// char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, size_t start, size_t len);
const char			*ft_skipspace(const char *str);
int					ft_free_array(char **str);
size_t				ft_array_len(char **arr);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(const  char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isdigit(int c);
int					ft_strcheck(char const *s, int (*f)(int));
int					ft_isalpha(int c);
int					ft_isalnum(int c);
char				*ft_replace(char *dst, char *src, size_t start, size_t end);

#endif
