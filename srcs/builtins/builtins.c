/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:19 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/06 12:39:56 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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

int	check_builtin(t_cmd *cmd, t_data_exe *data_exe)
{
	char	*cmd;
	char	*option;
	char	*string;

	if (!cmd)
		return (EXIT_FAILURE);
	if (!ft_strncmp(cmd, "echo", 5))
		return (exec_echo(cmd, option, string));
	else if (!ft_strncmp(cmd, "cd", 2))
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "pwd", 3))
		return (exec_pwd());
	else if (!ft_strncmp(cmd, "export", 7))
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "env", 3))
		return (exec_env(data_exe->envp)); // TODO fix this
	else if (!ft_strncmp(cmd, "exit", 4))
		return (exec_exit());
	return (EXIT_FAILURE);
}
