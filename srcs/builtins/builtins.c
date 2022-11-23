/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:19 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/23 12:34:41 by abeznik       ########   odam.nl         */
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

// ? testing
// int	read_builtin(char *cmd, char *option, const char *STRING, t_lexer *lexer)
// {
// 	// printf("\tInput read_builtin: [ (%s) (%s) (%s) ]\n", cmd, option, STRING);
// 	if (!cmd)
// 		return (EXIT_FAILURE);
// 	if (!ft_strncmp(cmd, "echo", 5))
// 		return (exec_echo(cmd, option, STRING));
// 	else if (!ft_strncmp(cmd, "cd", 2))
// 		return (EXIT_SUCCESS);
// 	else if (!ft_strncmp(cmd, "pwd", 3))
// 		return (exec_pwd());
// 	else if (!ft_strncmp(cmd, "export", 7))
// 		return (EXIT_SUCCESS);
// 	else if (!ft_strncmp(cmd, "unset", 6))
// 		return (EXIT_SUCCESS);
// 	else if (!ft_strncmp(cmd, "env", 3))
// 		return (exec_env(lexer->envp));
// 	else if (!ft_strncmp(cmd, "exit", 4))
// 		return (exec_exit());
// 	return (EXIT_FAILURE);
// }

int	read_builtin(t_lexer *lexer)
{
	char	*cmd;
	char	*option;
	char	*string;
	
	// printf("\tInput read_builtin: [ (%s) (%s) (%s) ]\n", cmd, option, STRING);
	
	cmd = lexer->tokens[0].word;
	option = lexer->tokens[1].word;
	string = lexer->tokens[2].word;
	
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
		return (exec_env(lexer->envp));
	else if (!ft_strncmp(cmd, "exit", 4))
		return (exec_exit());
	return (EXIT_FAILURE);
}
