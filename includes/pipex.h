/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:58:01 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/13 03:04:47 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_cmd
{
	char	**cmdv;
	char	*pathname;
}				t_cmd;

typedef struct s_pipex
{
	char	**paths;
	t_cmd	*cmd;
	int		*pid;
	int		infile;
	int		outfile;
	int		**fd;
	int		nr_children;
	int		current_child;
	int		status;
	int		here_doc;
	char	*delimiter;
}				t_pipex;

int		ft_strncmp(const char *s1, const char *s2, int len);
char	*ft_strjoin(char const *s1, char const *s2);
// int		ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strlcpy(char *dest, const char *src, int size);

int		get_commands(t_pipex *pipex, char **argv, char **envp);

// Child processes
void	last_child(t_pipex *pipex, char *file, char **envp);
void	middle_children(t_pipex *pipex, char **envp);
void	first_child(t_pipex *pipex, char *file, char **envp);
void	handle_the_children(t_pipex *pipex, char **argv, char **envp);
void	wait_for_children(t_pipex *pipex);
void	fork_process(t_pipex *pipex);

// Pipes
void	close_pipe(int *fd);
void	close_pipes(t_pipex *pipex);
void	open_pipes(t_pipex *pipex);

void	exit_pipex(t_pipex *pipex, int status, char *message);
void	free_cmd(t_cmd *cmd);
void	free_strings(char **strings, int len);
void	free_ints(int **ints, int len);
int		nr_strings(char **strings);

int	read_from_cmdl(char *delimiter);
#endif
