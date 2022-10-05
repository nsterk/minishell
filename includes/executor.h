/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:50:02 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/05 17:54:36 by abeznik       ########   odam.nl         */
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

void	executor(t_table *table);

char	*search_path(char *file);
int		exec_cmd(int argc, char **argv);
int		simple_cmd(t_token *tokens);

#endif