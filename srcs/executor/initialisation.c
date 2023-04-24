/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialisation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 11:50:43 by abeznik       #+#    #+#                 */
/*   Updated: 2023/04/24 16:17:06 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	*st_find_in_envp(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

/**
 * Initialises paths from the environment paths.
 * 	1. Find PATH in env and save to tmp.
 * 	2. Check path.
 * 	3. Check malloc error.
 * 	4. Loop over path:
 * 		- Append path and / to tmp.
 * 		- Check malloc error.
 * 		- Free path.
 * 		- Set path to tmp.
 * 	5. Return path.
*/
char	**init_paths(char **envp)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	tmp = st_find_in_envp(envp);
	if (!tmp)
		path = ft_split("", ':');
	else
		path = ft_split(tmp + 5, ':');
	check_malloc(path, "init_paths split");
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		check_malloc(tmp, "init_paths strjoin");
		free(path[i]);
		path[i] = tmp;
		i++;
	}
	return (path);
}

/**
 * Init. here_doc.
 * 	Loop over command struct:
 * 		- Loop over command input:
 * 			1. Check if input type is here_doc:
 * 				- execute here_doc and save pipe end
 * 				- if return error
 * 					=> return exit failure
 * 			2. Go to next input
 * 		- Go to next command
 * 	Return exit success.
*/
int	init_heredoc(t_cmd *cmd)
{
	t_red	*i;

	while (cmd)
	{
		// printf("cmd: %s\n", cmd->exec->cmd);
		i = cmd->in;
		// printf("in: %s\n", i->filename);
		while (i)
		{
			// printf("in: %s\n", i->filename);
			if (i->type == HERE_DOC)
			{
				i->fd = here_doc(i->filename);
				// i->here_doc = 3;
				if (i->fd == -1)
					return (EXIT_FAILURE);
			}
			i = i->next;
			// printf("type: %d\n", i->type);
		}
		cmd = cmd->next;
		// printf("filename: %s\n", cmd->in->filename);
	}
	return (EXIT_SUCCESS);
}
