/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_cmd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 11:53:50 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 11:53:59 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	cmd_not_found(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": no such file or directory", 2);
		exit(2);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
}

static char	*get_full_cmd(char *command, char **paths)
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

void	execute_cmd(t_cmd *cmd, t_exec *exec, t_mini_vars *vars)
{
	char	*full_cmd;

	if (!built_in(cmd, exec->cmd, vars))
		exit(vars->last_pid);
	full_cmd = get_full_cmd(exec->cmd, vars->paths);
	if (!full_cmd)
		cmd_not_found(exec->cmd);
	if (execve(full_cmd, exec->args, vars->env) < 0)
		exit_error(errno, "minishell", " : No such file or directory");
}

static void	child_process(t_cmd *cmd, t_mini_vars *vars, int end[2], int fd)
{
	int	status;

	close(end[READ]);
	if (redirect_input(cmd->input, fd, vars))
		exit(vars->last_pid);
	if (cmd->next)
		status = redirect_output(cmd->output, end[WRITE], vars);
	else
	{
		close(end[WRITE]);
		status = redirect_output(cmd->output, STDOUT_FILENO, vars);
	}
	if (status)
		exit(vars->last_pid);
	execute_cmd(cmd, cmd->exec, vars);
}

int	exec_forked_cmd(t_fork *forks, t_cmd *cmd, t_mini_vars *vars, int fd)
{
	int		end[2];

	if (pipe(end) < 0)
		exit_error(errno, "exec_forked_cmd", NULL);
	forks->pid = fork();
	if (forks->pid < 0)
		exit_error(errno, "exec_forked_cmd", NULL);
	else if (forks->pid == CHILD)
		child_process(cmd, vars, end, fd);
	else if (forks->pid > 0)
	{
		if (fd != 0)
			close(fd);
		close(end[WRITE]);
	}
	return (end[READ]);
}
