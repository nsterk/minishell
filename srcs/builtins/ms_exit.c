/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 11:46:53 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/22 10:08:48 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "builtins.h"
#include "../../includes/builtins.h" // ? I need this on my mac

/**
 * Bash overflows with exit codes over 255.
 * If no args => exit with last pid.
*/
static void	error(char *arg, char *error, int code, t_data_exe *data_exe)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	data_exe->last_pid = code;
}

static bool	st_is_numeric_arg(t_exec *exec)
{
	int	i;

	i = 2;
	while (i < exec->argc)
	{
		if (!ft_strcheck(exec->args[i], ft_isdigit))
			return (true);
		i++;
	}
	return (false);
}

static bool	st_help_exit(t_exec *exec, t_data_exe *data_exe)
{
	if (!ft_strcheck(exec->args[1], ft_isdigit))
	{
		if (exec->argc > 2)
		{
			error(NULL, "too many arguments", 1, data_exe);
			return (false);
		}
		else
			data_exe->last_pid = ft_atoi(exec->args[1]);
	}
	else
	{
		error(exec->args[1], ": numeric argument required", 255, data_exe);
		return (st_is_numeric_arg(exec));
	}
	return (true);
}

/**
 * exit with no option.
 * 	If no option is given, the exit status is 
 * 	that of the last command executed.
*/
int	exec_exit(t_exec *exec, t_data_exe *data_exe)
{
	bool	should_exit;

	ft_putendl_fd("exit", STDERR_FILENO);
	should_exit = true;
	if (exec->argc > 1)
		should_exit = st_help_exit(exec, data_exe);
	if (should_exit)
		exit((unsigned char)data_exe->last_pid);
	return (data_exe->last_pid);
}
