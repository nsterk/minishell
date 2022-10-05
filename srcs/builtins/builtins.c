/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:19 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/05 19:41:00 by abeznik       ########   odam.nl         */
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

int	read_builtin(char *cmd)
{
	printf("\tInput read_builtin: %s\n", cmd);
	if (!cmd)
		return (EXIT_FAILURE);
	if (!ft_strncmp(cmd, "echo", 5))
		// exec_echo
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "cd", 2))
		// exec_echo
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "pwd", 3))
		return (exec_pwd());
	else if (!ft_strncmp(cmd, "export", 7))
		// exec_echo
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "unset", 6))
		// exec_echo
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "env", 3))
		// exec_echo
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cmd, "exit", 4))
		// exec_echo
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
