/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:19 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 12:17:28 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	hash_cmd(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5))
		return (0);
	if (!ft_strncmp(cmd, "cd", 2))
		return (2);
	if (!ft_strncmp(cmd, "pwd", 3))
		return (3);
	if (!ft_strncmp(cmd, "export", 7))
		return (4);
	if (!ft_strncmp(cmd, "unset", 6))
		return (5);
	if (!ft_strncmp(cmd, "env", 3))
		return (6);
	if (!ft_strncmp(cmd, "exit", 4))
		return (7);
	return (EXIT_FAILURE);
}

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

int	read_builtin(char *cmd, char *option, const char *STRING, t_lexer *lexer)
{
	printf("\tInput read_builtin: [ %s %s %s ]\n", cmd, option, STRING); // ? testing
	if (!cmd)
		return (EXIT_FAILURE);
	// if (!ft_strncmp(cmd, "echo", 5)) // echo
	// 	return (exec_echo(cmd, option));
	// else if (!ft_strncmp(cmd, "cd", 2)) // cd
	// 	return (EXIT_SUCCESS);
	// else if (!ft_strncmp(cmd, "pwd", 3)) // pwd
	// 	return (exec_pwd());
	// else if (!ft_strncmp(cmd, "export", 7)) // export
	// 	return (EXIT_SUCCESS);
	// else if (!ft_strncmp(cmd, "unset", 6)) // unset
	// 	return (EXIT_SUCCESS);
	// else if (!ft_strncmp(cmd, "env", 3)) // env
	// 	return (EXIT_SUCCESS);
	// else if (!ft_strncmp(cmd, "exit", 4)) // exit
	// 	return (EXIT_SUCCESS);
	// return (EXIT_FAILURE);

	switch (hash_cmd(cmd))
	{
		case 0:
			return (exec_echo(cmd, option, STRING));	
		case 2:
			return (EXIT_SUCCESS);
		case 3:
			return (exec_pwd());
		case 4:
			return (EXIT_SUCCESS);
		case 5:
			return (EXIT_SUCCESS);
		case 6:
			return (exec_env(lexer->envp));
		case 7:
			return (exec_exit());
	}
	return (EXIT_FAILURE);
}
