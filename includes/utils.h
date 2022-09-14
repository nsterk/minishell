#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

/**
 * GNL utils.
 */
int		get_next_line(int fd, char **line);
char	*ft_strndup(char *src, size_t n);
char	*ft_strgjoin(char *s1, char *s2, int len_s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

/**
 * Libft functions.
 */
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
// int					ft_isalnum(int c);
// int					ft_isalpha(int c);
// int					ft_isascii(int c);
// int					ft_isdigit(int c);
// int					ft_isprint(int c);
char				*ft_itoa(int n);
// void				ft_lstadd_back(t_list **lst, t_list *new);
// void				ft_lstadd_front(t_list **lst, t_list *new);
// void				ft_lstclear(t_list **lst, void (*del)(void *));
// void				ft_lstdelone(t_list *lst, void (*del)(void *));
// void				ft_lstiter(t_list *lst, void (*f)(void *));
// t_list				*ft_lstlast(t_list *lst);
// t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
// 						void (*del)(void *));
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *str, int c, size_t n);
// void				ft_putchar_fd(char c, int fd);
// void				ft_putendl_fd(char *s, int fd);
// void				ft_putnbr_fd(int n, int fd);
// void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size); //also declared for GNL
size_t				ft_strlen(const char *s); //also declared for GNL
// char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int             	ft_strcmp(char *s1, char *s2);
// char				*ft_strnstr(const char *haystack, const char *needle,
// 						size_t len);
// char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
// int					ft_tolower(int c);
// int					ft_toupper(int c);
const char			*ft_skipspace(const char *str);
int					ft_free_array(char **str);

#	endif