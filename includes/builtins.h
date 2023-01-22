/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:58 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/22 11:41:13 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// # include "parser.h"
# include "executor.h"

// # include "minishell.h"
// # include "utils.h"

# include "stdlib.h" // getenv, EXIT_...
# include "unistd.h"

# define EXPORT 1
# define UNSET 0
# define NOT_FOUND -1
# define ADD_NEW -2

/**
 * builtins
*/
int			check_builtin(t_cmd *cmd, t_data_exe *exec);
int			special_builtin(char *cmd);

/**
 * pwd
*/
// int			exec_pwd(void); // ? testing
int			exec_pwd(t_data_exe *data_exe);

/**
 * echo
*/
// int			exec_echo(char *cmd, char *option, const char *STRING); // ? testing
int			exec_echo(char **args, t_data_exe *data_exe);

/**
 * exit
*/
// int			exec_exit(void); // ? testing
int			exec_exit(t_exec *exec, t_data_exe *data_exe);

/**
 * env
*/
// int			exec_env(char **envp); // ? testing
int			exec_env(char **envp, t_data_exe *data_exe);

/**
 * export
*/
int			exec_export(char **args, t_data_exe *data_exe);
char		**ft_export(char *arg, char **envp, t_data_exe *data_exe);
int			search_envp(char *args, char **envp, t_data_exe *data_exe, char c);
void		error_message(char *arg, t_data_exe *data_exe);
void		ms_single_export(char **envp);

/**
 * unset
*/
int			exec_unset(char **args, t_data_exe *data_exe);

/**
 * cd
*/
int			exec_cd(char **args, t_data_exe *data_exe);
void		set_new_paths(char *new_pwd, char *old_pwd, t_data_exe *data_exe);
char		*get_envp_value(char **envp, char *key);

/**
 * utils
*/
int			check_for_error(char *arg, int type, char **env);
void		copy_line_envp(char **new_env, char **env, int new_env_i, int env_i);

#endif
