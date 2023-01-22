/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 10:28:10 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/22 10:58:01 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "builtins.h"
#include "../../includes/builtins.h" // ? I need this on my mac

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

void	set_new_paths(char *new_pwd, char *old_pwd, t_data_exe *data_exe)
{
	char	*new_curr_pwd;
	char	*new_old_pwd;

	new_curr_pwd = ft_strjoin("PWD=", new_pwd);
	check_malloc(new_curr_pwd, "home_path");
	new_old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	check_malloc(new_old_pwd, "home_path");
	data_exe->envp = ft_export(new_curr_pwd, data_exe->envp, data_exe);
	data_exe->envp = ft_export(new_old_pwd, data_exe->envp, data_exe);
	free(new_curr_pwd);
	free(new_old_pwd);
	return ;
}
