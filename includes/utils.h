/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:09:43 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/15 15:12:03 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

typedef enum e_status
{
	EXIT_MINISHELL
}	t_status;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Exit functions.
 */
void				exit_minishell(int status);

/**
 * GNL functions.
 */
int					get_next_line(int fd, char **line);
char				*ft_strndup(char *src, size_t n);
char				*ft_strgjoin(char *s1, char *s2, int len_s2);

/**
 * Pipex functions.
 */
typedef struct s_command
{
	char	**cmdv;
	char	*pathname;
}				t_command;

typedef struct s_pipex
{
	char	**paths;
	t_command	*command;
	int		*pid;
	int		infile;
	int		outfile;
	int		**fd;
	int		nr_children;
	int		current_child;
	int		status;
	int		here_doc;
	char	*delimiter;
	int		offset;
}				t_pipex;

// int		ft_strncmp(const char *s1, const char *s2, int len);
// char	*ft_strjoin(char const *s1, char const *s2);
// int		ft_strlen(const char *s);
// char	*ft_strdup(const char *src);
// char	**ft_split(char const *s, char c);
// char	*ft_strtrim(char const *s1, char const *set);
// int		ft_strlcpy(char *dest, const char *src, int size);
// int		ft_strcmp(char *s1, char *s2);

int		get_commands(t_pipex *pipex, char **argv, char **envp);

// Child processes
void	last_child(t_pipex *pipex, char *file, char **envp);
void	middle_children(t_pipex *pipex, char **envp);
void	first_child(t_pipex *pipex, char *file, char **envp);
void	handle_the_children(t_pipex *pipex, char **argv, char **envp);
void	wait_for_children(t_pipex *pipex);
void	fork_process(t_pipex *pipex);

// Pipes
void	close_pipes(t_pipex *pipex);
void	open_pipes(t_pipex *pipex);

void	exit_pipex(t_pipex *pipex, int status, char *message);
void	free_strings(char **strings, int len);
int		nr_strings(char **strings);

int		read_from_cmdl(char *delimiter);

/**
 * Libft functions.
 */
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_itoa(int n);
int					ft_isspace(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *str, int c, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, char *src);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
const char			*ft_skipspace(const char *str);
int					ft_free_array(char **str);
size_t				ft_arraylen(char **arr);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);

/**
 * Linked list functions.
 */

// t_list				*ft_lstnew(void *content);
// int					ft_lstadd_back(t_list **lst, t_list *new);
// void				ft_lstadd_front(t_list **lst, t_list *new);
// t_list				*ft_lstlast(t_list *lst);
// void				ft_lstclear(t_list **lst, void (*del)(void *));
// void				ft_lstdelone(t_list *lst, void (*del)(void *));
// void				ft_lstiter(t_list *lst, void (*f)(void *));

#	endif

/**
 * TAKE WHAT YOU NEED!
 */

// int					ft_isalnum(int c);
// int					ft_isalpha(int c);
// int					ft_isascii(int c);
// int					ft_isdigit(int c);
// int					ft_isprint(int c);

// t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
// 						void (*del)(void *));

// void				ft_putchar_fd(char c, int fd);
// void				ft_putnbr_fd(int n, int fd);

// char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// char				*ft_strnstr(const char *haystack, const char *needle,
// 						size_t len);
// char				*ft_strrchr(const char *s, int c);

// int					ft_tolower(int c);
// int					ft_toupper(int c);
// size_t				ft_strnlen(const char *s, size_t maxlen);
// size_t				ft_strclen(const char *s, char c);
// char				*ft_strcdup(const char *src, char c);
// char				*ft_strccpy(char *dest, const char *src, char c);