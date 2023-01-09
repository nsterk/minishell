/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 13:48:56 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/08 16:25:35 by arthurbezni   ########   odam.nl         */
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

void	execute_cmd(t_cmd *cmd, t_exec *exec, t_data_exe *data_exe)
{
	char	*full_cmd;

	if (!check_builtin(cmd, data_exe))
		exit(data_exe->last_pid);
	full_cmd = st_get_full_cmd(exec->cmd, data_exe->paths);
	if (!full_cmd)
		st_cmd_not_found(exec->cmd);
	if (execve(full_cmd, exec->args, data_exe->envp) < 0)
		exit_error(errno, "momoshell", " : No such file or directory");
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
		exit_error(errno, "exec_piped_cmd pipe", NULL);
	proc->pid = fork();
	if (proc->pid < 0)
		exit_error(errno, "exec_piped_cmd fork", NULL);
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
