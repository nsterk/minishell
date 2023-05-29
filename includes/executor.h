
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
# include "signals.h"
# include "minishell.h"

// # include "minishell.h"
// # include "builtins.h"
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

typedef struct s_data t_data;

/**
 * Process data:
 * 	- process id
 * 	- next process
*/
typedef struct s_proc {
	pid_t			pid;
	struct s_proc	*next;
}	t_proc;

/**
 * executor.c + statics
*/
// void		executor(t_lexer *lexer, t_cmd *cmd, t_data *data);
// void		executor(t_lexer *lexer); // ? testing
void		executor(t_data *data);
// static int		st_simple_cmd(t_cmd *cmd, t_data *data);
// static void		st_piped_cmd(t_proc **current, t_cmd *cmd, t_data *data);
// static void		st_wait_processes(t_proc *proc, t_data *data);
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
int			redirect_in(t_red *input, int fd, t_data *data);
int			redirect_out(t_red *output, int fd, t_data *data);
// static int		st_file_error(const char *filename);
// static int		st_duplicate(int fd, int in_out_fileno, t_data *data);

/**
 * exec_cmd.c + statics
*/
int			exec_piped_cmd(t_proc *proc, t_cmd *cmd, t_data *data, int fd);
void		execute_cmd(t_cmd *cmd, t_data *data);
// static char		*st_get_full_cmd(char *command, char **paths);
// static void		st_cmd_not_found(char *cmd);
// static void		st_child_process(int end[2], char *delim);

int			check_builtin(t_cmd *cmd, t_data *data);
int			special_builtin(char *cmd);

int			file_error(const char *filename);

#endif
