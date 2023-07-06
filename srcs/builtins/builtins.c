/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:44:20 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/06 17:15:55 by nsterk        ########   odam.nl         */
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
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "export"))
		return (1);
	else if (!ft_strcmp(cmd, "unset"))
		return (1);
	else if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

int	check_builtin(t_cmd *cmds, t_data *data)
{
	char	*tmp;

	if (!cmds)
		return (EXIT_FAILURE);
	tmp = cmds->argv[0];
	if (!ft_strcmp(tmp, "echo"))
		return (exec_echo(cmds->argv, data));
	else if (!ft_strcmp(tmp, "cd"))
		return (exec_cd(cmds->argv, data));
	else if (!ft_strcmp(tmp, "pwd"))
		return (exec_pwd(data));
	else if (!ft_strcmp(tmp, "export"))
		return (exec_export(cmds->argv, data));
	else if (!ft_strcmp(tmp, "unset"))
		return (exec_unset(cmds->argv, data));
	else if (!ft_strcmp(tmp, "env"))
		return (exec_env(cmds->argv, data));
	else if (!ft_strcmp(tmp, "exit"))
		return (exec_exit(cmds, data));
	return (EXIT_FAILURE);
}
