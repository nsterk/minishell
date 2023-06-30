/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:45:26 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:45:28 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*get_envp_value(char **envp, char *key)
{
	int	len;
	int	i;

	len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, len) && envp[i][len] == '=')
			return (&envp[i][len + 1]);
		i++;
	}
	return (NULL);
}

void	set_new_paths(char *new_pwd, char *old_pwd, t_data *data)
{
	char	*new_curr_pwd;
	char	*new_old_pwd;

	new_curr_pwd = ft_strjoin("PWD=", new_pwd);
	check_malloc(new_curr_pwd, "home_path");
	new_old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	check_malloc(new_old_pwd, "home_path");
	data->envp = ft_export(new_curr_pwd, data->envp, data);
	data->envp = ft_export(new_old_pwd, data->envp, data);
	free(new_curr_pwd);
	free(new_old_pwd);
	return ;
}
