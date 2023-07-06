/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:52:18 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/06 13:59:47 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	st_cmd_not_found(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		ft_putstr_fd("momoshell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": no such file or directory", 2);
		exit(2);
	}
	else
	{
		ft_putstr_fd("momoshell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
}

static char	*st_get_full_cmd(char *cmd, char **paths)
{
	char	*tmp;
	int		i;

	if (cmd && *cmd == '\0')
		return (NULL);
	if (!access(cmd, X_OK))
		return (cmd);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		check_malloc(tmp, "get_full_cmd");
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

/**
 * Executes the command.
 * 	1. If builtin => exit last pid.
 * 	2. Get full command (w/ path).
 * 	3. If not command => throw cmd not found error.
 * 	4. Execute command using execve => throw error if failure.
*/
void	execute_cmd(t_cmd *cmd, t_data *data)
{
	char	*full_cmd;

	if (!check_builtin(cmd, data))
		exit(data->last_pid);
	full_cmd = st_get_full_cmd(cmd->argv[0], data->paths);
	if (!full_cmd)
		st_cmd_not_found(cmd->argv[0]);
	if (execve(full_cmd, cmd->argv, data->envp) < 0)
		exit_error(errno, "momoshell", " : No such file or directory");
}

/**
 * Executes child process.
 * 	1. Close pipe read end.
 * 	2. If input redirection fails => exit last pid.
 * 	3.	- If command has a next cmd
 * 			=> output redirection using pipe write end as fd
 * 		- Else
 * 			=> close pipe write end
 * 			=> output redirection using standard output (1)
 * 	4. If status = 1 (failure)
 * 		=> exit last pid
 * 	5. Execute command.
*/
static void	st_child_process(t_cmd *cmd, t_data *data, int pend[2], int fd)
{
	int	status;

	close(pend[READ]);
	if (redirect_in(cmd->in, fd, data))
		exit(data->last_pid);
	if (cmd->next)
		status = redirect_out(cmd->out, pend[WRITE], data);
	else
	{
		close(pend[WRITE]);
		status = redirect_out(cmd->out, STDOUT_FILENO, data);
	}
	if (status)
		exit(data->last_pid);
	execute_cmd(cmd, data);
}

/**
 * Executes piped commands.
 * 	1. Check pipe error.
 * 	2. Fork process.
 * 	3. 	- If fork error => exit error
 * 		- If child => execute child process
 * 		- If > 0
 * 			- if fd != 0 => close fd
 * 			- close pipe write end
 * 	4. Return pipe read end.
*/
int	exec_piped_cmd(t_proc *proc, t_cmd *cmd, t_data *data, int fd)
{
	int		pend[2];

	if (pipe(pend) < 0)
		exit_error(errno, "exec_piped_cmd pipe", NULL);
	proc->pid = fork();
	if (proc->pid < 0)
		exit_error(errno, "minishell: fork", "Resource temporarily unavailable");
	else if (proc->pid == CHILD)
		st_child_process(cmd, data, pend, fd);
	else if (proc->pid > 0)
	{
		if (fd != 0)
			close(fd);
		close(pend[WRITE]);
	}
	return (pend[READ]);
}
