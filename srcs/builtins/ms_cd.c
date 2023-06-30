/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:45:51 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:45:52 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	st_home_path(char **envp, t_data *data, char *path)
{
	char	*home_path_str;
	char	*curr_pwd;

	home_path_str = get_envp_value(envp, "HOME");
	if (!home_path_str)
	{
		ft_putendl_fd("momoshell: cd: HOME not set", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	curr_pwd = get_envp_value(envp, "PWD");
	if (chdir(home_path_str) == -1)
		return (file_error(path));
	set_new_paths(home_path_str, curr_pwd, data);
	return (EXIT_SUCCESS);
}

static int	st_oldpwd_path(char **envp, t_data *data, char *path)
{
	char	*old_pwd;
	char	*curr_pwd;

	old_pwd = get_envp_value(envp, "OLDPWD");
	check_malloc(old_pwd, "oldpwd_path");
	curr_pwd = get_envp_value(envp, "PWD");
	check_malloc(curr_pwd, "oldpwd_path");
	if (chdir(old_pwd) == -1)
		return (file_error(path));
	set_new_paths(old_pwd, curr_pwd, data);
	return (EXIT_SUCCESS);
}

static int	st_relative_path(t_data *data, char *path)
{
	char	*curr_pwd;
	char	*new_pwd;

	curr_pwd = getcwd(NULL, 0);
	check_malloc(curr_pwd, "relative_path");
	if (chdir(path) == -1)
		return (file_error(path));
	new_pwd = getcwd(NULL, 0);
	check_malloc(new_pwd, "relative_path");
	set_new_paths(new_pwd, curr_pwd, data);
	free(curr_pwd);
	free(new_pwd);
	return (EXIT_SUCCESS);
}

static int	st_absolute_path(char **envp, t_data *data, char *path)
{
	char	*home_path_str;

	home_path_str = get_envp_value(envp, "PWD");
	if (chdir(path) == -1)
		return (file_error(path));
	set_new_paths(path, home_path_str, data);
	return (EXIT_SUCCESS);
}

int	exec_cd(char **args, t_data *data)
{
	if (!args[1])
		data->last_pid = st_home_path(data->envp, data, args[1]);
	else if (!ft_strncmp(args[1], "-", 1))
		data->last_pid = st_oldpwd_path(data->envp, data, args[1]);
	else if (args[1][0] == '/')
		data->last_pid = st_absolute_path(data->envp, data, args[1]);
	else
		data->last_pid = st_relative_path(data, args[1]);
	return (EXIT_SUCCESS);
}
