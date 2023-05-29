
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
	int	i;

	i = 2;
	while (i < cmd->argc)
	{
		if (!ft_strcheck(cmd->args[i], ft_isdigit))
			return (true);
		i++;
	}
	return (false);
}

static bool	st_help_exit(t_cmd *cmd, t_data *data)
{
	if (!ft_strcheck(cmd->args[1], ft_isdigit))
	{
		if (cmd->argc > 2)
		{
			error(NULL, "too many arguments", 1, data);
			return (false);
		}
		else
			data->last_pid = ft_atoi(cmd->args[1]);
	}
	else
	{
		error(cmd->args[1], ": numeric argument required", 255, data);
		return (st_is_numeric_arg(cmd));
	}
	return (true);
}

/**
 * exit with no option.
 * 	If no option is given, the exit status is 
 * 	that of the last command executed.
*/
int	exec_exit(t_cmd *cmd, t_data *data)
{
	bool	should_exit;

	ft_putendl_fd("exit", STDERR_FILENO);
	should_exit = true;
	if (cmd->argc > 1)
		should_exit = st_help_exit(cmd, data);
	if (should_exit)
		exit((unsigned char)data->last_pid);
	return (data->last_pid);
}
