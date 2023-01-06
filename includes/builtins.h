/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:58 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/06 15:32:45 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "executor.h"
# include "utils.h"

# include "stdlib.h" // getenv

int			check_builtin(t_cmd *cmd, t_data_exe *exec);
int			special_builtin(char *cmd);

int			exec_pwd(void);
int			exec_echo(char *cmd, char *option, const char *STRING);
int			exec_exit(void);
int			exec_env(char **envp);

#endif
