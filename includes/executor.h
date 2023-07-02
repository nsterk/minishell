/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:48:37 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/02 12:15:51 by abeznik       ########   odam.nl         */
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
# include "signals.h"
# include "minishell.h"

# define READ 0
# define WRITE 1
# define CHILD 0
# define NO_PIPE -1

/**
 * Global variable to have the state of the momoshell.
*/
int						g_state;
# define EXECUTING 0
# define COMMAND 1
# define HEREDOC_INPUT 2

typedef struct s_data	t_data;

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
void					executor(t_data *data);

/**
 * init.c + statics
*/
int						init_heredoc(t_cmd *cmd);
char					**init_paths(char **envp);

/**
 * here_doc.c + statics
*/
int						here_doc(char *delim);

/**
 * redirects.c + statics
*/
int						redirect_in(t_red *input, int fd, t_data *data);
int						redirect_out(t_red *output, int fd, t_data *data);

/**
 * exec_cmd.c + statics
*/
int						exec_piped_cmd(t_proc *proc, t_cmd *cmd, \
	t_data *data, int fd);
void					execute_cmd(t_cmd *cmd, t_data *data);

int						check_builtin(t_cmd *cmd, t_data *data);
int						special_builtin(char *cmd);

int						file_error(const char *filename);

#endif
