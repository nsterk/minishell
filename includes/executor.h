/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:50:02 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/04 15:08:42 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/**
 * Needed libs.
 */
# include <unistd.h> // execve

/**
 * Minishell libs.
 */
# include "lexer.h"
# include "parser.h"
# include "utils.h"
# include "builtins.h"

# define READ 0
# define WRITE 1
# define CHILD 0
# define NO_PIPE -1

int	g_state;
# define EXECUTING 0
# define COMMAND 1
# define HEREDOC_INPUT 2

typedef struct s_exec
{
	char			**paths;
	char			**env;
	struct s_cmd	*cmd;
	pid_t			last_pid;
}	t_exec;

typedef struct s_proc
{
	pid_t			pid;
	struct t_proc	*next;
}	t_proc;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	int		len;
	t_io	*in;
	t_io	*out;
	struct s_cmd *next;
}	t_cmd;

void				executor(t_lexer *lexer, t_cmd *cmd, t_exec *exec);
// static int			st_simple_cmd(t_cmd *cmd, t_exec *exec); // ? static
// static void			st_piped_cmd(t_proc **current, t_cmd *cmd, t_exec *exec); // ? static
// static void			st_wait_processes(t_proc *proc, t_exec *exec); // ? static
// static t_proc		*st_new_process(t_proc *proc) // ? static

int					init_heredoc(t_cmd *cmd);

char				**init_paths(char **env);
// static char			*st_find_in_env(char **env); // ? static

int					here_doc(char *delim);
// static void			st_child_process(int end[2], char *delim); // ? static
// static char			*st_get_text(char *delim); // ? static
// static int			st_delim_in_line(char *line, char *delim, int len); // ? static

int					read_builtin(t_cmd *cmd);

int					redirect_in(t_io *input, int fd, t_exec *exec);
int					redirect_out(t_io *output, int fd, t_exec *exec);
// static int			st_file_error(const char *filename); // ? static
// static int			st_duplicate(int fd, int in_out_fileno, t_exec *exec); // ? static

void				execute_cmd(t_cmd *cmd, t_exec *exec);

#endif
