/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cmd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 13:48:56 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/06 15:29:38 by abeznik       ########   odam.nl         */
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

static char	*st_get_full_cmd(char *command, char **paths)
{
	char	*temp;
	int		i;

	if (command && *command == '\0')
		return (NULL);
	if (!access(command, X_OK))
		return (command);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], command);
		ft_check_malloc(temp, "get_full_cmd");
		if (!access(temp, X_OK))
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

void	execute_cmd(t_cmd *cmd, t_exec *exec, t_data_exe *data_exe)
{
	char	*full_cmd;

	if (!check_builtin(cmd, data_exe))
		exit(data_exe->last_pid);
	full_cmd = st_get_full_cmd(exec->cmd, data_exe->paths);
	if (!full_cmd)
		st_cmd_not_found(exec->cmd);
	if (execve(full_cmd, exec->args, data_exe->envp) < 0)
		exit_error(errno, "minishell", " : No such file or directory");
}

static void	st_child_process(t_cmd *cmd, t_data_exe *data_exe, int pend[2], int fd)
{
	int	status;

	close(pend[READ]);
	if (redirect_in(cmd->in, fd, data_exe))
		exit(data_exe->last_pid);
	if (cmd->next)
		status = redirect_out(cmd->out, pend[WRITE], data_exe);
	else
	{
		close(pend[WRITE]);
		status = redirect_out(cmd->out, STDOUT_FILENO, data_exe);
	}
	if (status)
		exit(data_exe->last_pid);
	execute_cmd(cmd, cmd->exec, data_exe);
}

int	exec_piped_cmd(t_proc *proc, t_cmd *cmd, t_data_exe *data_exe, int fd)
{
	int		pend[2];

	if (pipe(pend) < 0)
		exit_error(errno, "exec_piped_cmd", NULL);
	proc->pid = fork();
	if (proc->pid < 0)
		exit_error(errno, "exec_piped_cmd", NULL);
	else if (proc->pid == CHILD)
		st_child_process(cmd, data_exe, pend, fd);
	else if (proc->pid > 0)
	{
		if (fd != 0)
			close(fd);
		close(pend[WRITE]);
	}
	return (pend[READ]);
}
