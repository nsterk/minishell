/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:46:40 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:46:42 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	**st_edit_envp_export(char **envp, char *args, \
	int row_nr, int size_envp)
{
	char	**new_envp;
	int		i;

	new_envp = (char **)malloc((size_envp + 1) * sizeof(char *));
	check_malloc(new_envp, "edit_envp_export");
	i = 0;
	while (envp[i])
	{
		if (i == row_nr)
			copy_line_envp(new_envp, &args, i, 0);
		else
			copy_line_envp(new_envp, envp, i, i);
		i++;
	}
	if (i == row_nr)
	{
		copy_line_envp(new_envp, &args, i, 0);
		i++;
	}
	new_envp[i] = NULL;
	ft_free_array(envp);
	return (new_envp);
}

int	search_envp(char *args, char **envp, t_data *data, char c)
{
	int		orig_len;
	int		len;
	int		i;

	len = 0;
	orig_len = ft_strlen(args);
	while (args[len] && args[len] != c)
		len++;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], args, len) == 0)
		{
			if (envp[i][len] == '=')
				return (i);
		}
		i++;
	}
	if (len == 0)
		error_message(args, data);
	if (len < orig_len)
		return (ADD_NEW);
	return (NOT_FOUND);
}

char	**ft_export(char *arg, char **envp, t_data *data)
{
	int		row_nr;
	int		size_envp;
	char	**new_envp;

	size_envp = 0;
	while (envp[size_envp])
		size_envp++;
	row_nr = search_envp(arg, envp, data, '=');
	if (row_nr == NOT_FOUND)
		return (envp);
	else if (row_nr == ADD_NEW)
	{
		size_envp++;
		row_nr = size_envp - 1;
	}
	new_envp = st_edit_envp_export(envp, arg, row_nr, size_envp);
	check_malloc(new_envp, "ft_export");
	data->last_pid = 0;
	return (new_envp);
}

int	exec_export(char **args, t_data *data)
{
	int	i;

	if (!args[1])
		ms_single_export(data->envp);
	i = 1;
	while (args[i])
	{
		if (check_for_error(args[i], EXPORT, data->envp))
			error_message(args[i], data);
		else
			data->envp = ft_export(args[i], data->envp, data);
		i++;
	}
	return (EXIT_SUCCESS);
}
