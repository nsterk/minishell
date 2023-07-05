/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:46:12 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/05 18:31:19 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "executor.h"

# include "stdlib.h"// getenv, EXIT_...
# include "unistd.h"

# define EXPORT 1
# define UNSET 0
# define NOT_FOUND -1
# define ADD_NEW -2

typedef struct s_data	t_data;

/**
 * builtins
*/
int			check_builtin(t_cmd *cmd, t_data *data);
int			special_builtin(char *cmd);

/**
 * pwd
*/
int			exec_pwd(t_data *data);

/**
 * echo
*/
int			exec_echo(char **args, t_data *data);

/**
 * exit
*/
int			exec_exit(t_cmd *cmd, t_data *data);

/**
 * env
*/
int			exec_env(char **envp, t_data *data);

/**
 * export
*/
int			exec_export(char **args, t_data *data);
char		**ft_export(char *arg, char **envp, t_data *data);
int			search_envp(char *args, char **envp, t_data *data, char c);
void		error_message(char *arg, t_data *data);
void		ms_single_export(char **envp);

/**
 * unset
*/
int			exec_unset(char **args, t_data *data);

/**
 * cd
*/
int			exec_cd(char **args, t_data *data);
void		set_new_paths(char *new_pwd, char *old_pwd, t_data *data);
char		*get_envp_value(char **envp, char *key);

/**
 * utils
*/
int			check_for_error(char *arg, int type, char **env);
void		copy_line_envp(char **new_env, char **env, \
	int new_env_i, int env_i);

#endif
