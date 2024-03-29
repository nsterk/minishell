/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:46:10 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/06 14:05:34 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * Bash overflows with exit codes over 255.
 * If no args => exit with last pid.
*/
static void	error(char *arg, char *error, int code, t_data *data)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	data->last_pid = code;
}

static bool	st_is_numeric_arg(t_cmd *cmd)
{
	int		i;

	i = 2;
	while (i < cmd->argc)
	{
		if (!ft_isdigital(cmd->argv[i]))
			return (true);
		i++;
	}
	return (false);
}

static bool	st_help_exit(t_cmd *cmd, t_data *data)
{
	if (!ft_isdigital(cmd->argv[1]))
	{
		if (cmd->argc > 2)
		{
			error(NULL, "too many arguments", 1, data);
			return (false);
		}
		else
			data->last_pid = ft_atoi(cmd->argv[1]);
	}
	else
	{
		error(cmd->argv[1], ": numeric argument required", 255, data);
		return (st_is_numeric_arg(cmd));
	}
	return (true);
}

/**
 * exit with no option.
 * 	If no option is given, the exit status is 
 * 	that of the last command executed.
 * ! Only case where it does NOT exit is "exit <number> <letter>"
 * ! Exit always exits with "exit <arg>", no matter the <arg> type
*/
int	exec_exit(t_cmd *cmd, t_data *data)
{
	bool	should_exit;

	ft_putendl_fd("exit", STDOUT_FILENO);
	should_exit = true;
	if (cmd->argc > 1)
		should_exit = st_help_exit(cmd, data);
	if (cmd->argc == 2)
		should_exit = true;
	if (should_exit)
		exit((unsigned char)data->last_pid);
	return (data->last_pid);
}
