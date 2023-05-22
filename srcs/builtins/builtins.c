
#include "builtins.h"
// #include "../../includes/builtins.h"

/**
 * Builtins:
 * 	echo + -n
 * 	cd + rel./abs. path
 * 	pwd
 * 	export
 * 	unset
 * 	env
 * 	exit
 */

int	special_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strncmp(cmd, "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd, "export", 7))
		return (1);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (1);
	else if (!ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

int	check_builtin(t_cmd *cmds, t_data_exe *data_exe)
{
	char	*tmp;
	
	tmp = cmds->args[0]; // ? testing
	// this is a comment
	// this is a comment 1
	if (!cmds)
		return (EXIT_FAILURE);
	if (!ft_strncmp(tmp, "echo", 5))
		return (exec_echo(cmds->args, data_exe));
	else if (!ft_strncmp(tmp, "cd", 2))
		return (exec_cd(cmds->args, data_exe));
	else if (!ft_strncmp(tmp, "pwd", 3))
		return (exec_pwd(data_exe));
	else if (!ft_strncmp(tmp, "export", 7))
		return (exec_export(cmds->args, data_exe));
	else if (!ft_strncmp(tmp, "unset", 6))
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(tmp, "env", 3))
		return (exec_env(data_exe->envp, data_exe));
	else if (!ft_strncmp(tmp, "exit", 4))
		return (exec_exit(cmds, data_exe));
	return (EXIT_FAILURE);
}
