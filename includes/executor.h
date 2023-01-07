/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:50:02 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/07 16:52:50 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/**
 * Needed libs.
 */
# include <unistd.h> // execve
# include <fcntl.h> // open/read/... modes

/**
 * Minishell libs.
 */
# include "parser.h"
// # include "builtins.h"

// # include "minishell.h"
// # include "lexer.h"
// # include "utils.h"

# define READ 0
# define WRITE 1
# define CHILD 0
# define NO_PIPE -1

/**
 * Global variable to have the state of the momoshell.
*/
int	g_state;
# define EXECUTING 0
# define COMMAND 1
# define HEREDOC_INPUT 2

/**
 * Process data:
 * 	- process id, and
 * 	- next process.
*/
typedef struct s_proc {
	pid_t			pid;
	struct s_proc	*next;
}	t_proc;

/**
 * Redirection type enum.
*/
typedef enum e_red_type {
	RED_IPUT,
	HERE_DOC,
	RED_OPUT,
	RED_OPUT_A
}	t_red_type;

/**
 * Redirection data:
 * 	- redirection type,
 * 	- file name,
 * 	- heredoc,
 * 	- next command.
*/
typedef struct s_red {
	t_red_type		type;
	char			*filename;
	int				here_doc;
	struct s_red	*next;
}	t_red;

/**
 * Command execution data: 
 * 	- command itself, 
 * 	- the args, and 
 * 	- the length.
*/
typedef struct s_exec {
	char	*cmd;
	char	**args;
	int		len;
}	t_exec;

/**
 * Command data: 
 * 	- execution info, 
 * 	- input, 
 *  - output and 
 *  - next command.
*/
typedef struct s_cmd {
	t_exec			*exec;
	t_red			*in;
	t_red			*out;
	struct s_cmd	*next;
}	t_cmd;

/**
 * Executor data:
 * 	- environment paths,
 * 	- paths of commands, and
 * 	- last process id.
*/
typedef struct s_data_exe {
	char	**envp;
	char	**paths;
	pid_t	last_pid;
}	t_data_exe;

/**
 * executor.c + statics
*/
// void		executor(t_lexer *lexer, t_cmd *cmd, t_data_exe *data_exe);
void		executor(t_lexer *lexer); // ? testing
// static int		st_simple_cmd(t_cmd *cmd, t_data_exe *data_exe);
// static void		st_piped_cmd(t_proc **current, t_cmd *cmd, t_data_exe *data_exe);
// static void		st_wait_processes(t_proc *proc, t_data_exe *data_exe);
// static t_proc	*st_new_process(t_proc *proc);

/**
 * init.c + statics
*/
int			init_heredoc(t_cmd *cmd);
char		**init_paths(char **envp);
// static char			*st_find_in_env(char **env);

/**
 * here_doc.c + statics
*/
int			here_doc(char *delim);
// static char		*st_get_text(char *delim);
// static int		st_delim_in_line(char *line, char *delim, int len);

/**
 * redirects.c + statics
*/
int			redirect_in(t_red *input, int fd, t_data_exe *data_exe);
int			redirect_out(t_red *output, int fd, t_data_exe *data_exe);
// static int		st_file_error(const char *filename);
// static int		st_duplicate(int fd, int in_out_fileno, t_data_exe *data_exe);

/**
 * exec_cmd.c + statics
*/
int			exec_piped_cmd(t_proc *proc, t_cmd *cmd, \
				t_data_exe *data_exe, int fd);
void		execute_cmd(t_cmd *cmd, t_exec *exec, t_data_exe *data_exe);
// static char		*st_get_full_cmd(char *command, char **paths);
// static void		st_cmd_not_found(char *cmd);
// static void		st_child_process(int end[2], char *delim);

int			check_builtin(t_cmd *cmd, t_data_exe *exec);
int			special_builtin(char *cmd);

#endif
