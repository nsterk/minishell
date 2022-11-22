/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:50:02 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/22 12:13:45 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/**
 * Needed libs.
 */
# include <unistd.h> // execve

/**
 * Minishell libs.
 */
# include "lexer.h"
# include "parser.h"
# include "utils.h"
# include "builtins.h"

// void	executor(t_lexer *lexer);
// void	executor(char *cmd, char *option, const char *STRING); // ? testing
void	executor(char *cmd, char *option, const char *STRING, t_lexer *lexer); // ? testing

// char	*search_path(char *file);
// int		exec_cmd(int argc, char **argv);
// int		simple_cmd(t_token *tokens);

#endif
