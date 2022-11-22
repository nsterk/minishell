/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:58 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 14:18:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parser.h"
# include "executor.h"
# include "utils.h"
# include "stdlib.h" // getenv

// int	read_builtin(char *cmd);
// int	read_builtin(char *cmd, char *option, const char *STRING); // ? testing
int	read_builtin(char *cmd, char *option, const char *STRING, t_lexer *lexer); // ? testing

int	exec_pwd(void);
int	exec_echo(char *cmd, char *option, const char *STRING);
int	exec_exit(void);
int	exec_env(char **envp);

#endif
