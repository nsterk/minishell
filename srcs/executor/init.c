/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 11:50:43 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/04 14:57:35 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// TODO fix struct
int	init_heredoc(t_cmd *cmd)
{
	t_io	*i;

	while (cmd)
	{
		i = cmd->input;
		while (i)
		{
			if (i->type == HERE_DOC)
			{
				i->heredoc = here_doc(i->filename);
				if (i->heredoc == -1)
					return (EXIT_FAILURE);
			}
			i = i->next;
		}
		cmd = cmd->next;
	}
	return (EXIT_SUCCESS);
}

static char	*st_find_in_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	**init_paths(char **env)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	temp = st_find_in_env(env);
	if (!temp)
		path = ft_split("", ':');
	else
		path = ft_split(temp + 5, ':');
	ft_check_malloc(path, "make_path_env");
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		ft_check_malloc(temp, "init_path");
		free(path[i]);
		path[i] = temp;
		i++;
	}
}
