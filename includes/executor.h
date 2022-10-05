/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:50:02 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/05 19:28:17 by abeznik       ########   odam.nl         */
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

void	executor(t_token *tokens);

// char	*search_path(char *file);
// int		exec_cmd(int argc, char **argv);
// int		simple_cmd(t_token *tokens);

#endif