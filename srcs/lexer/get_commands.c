/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_get_commands.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 16:39:13 by naomisterk    #+#    #+#                 */
/*   Updated: 2022/09/13 19:39:38 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
This is the pipex file where I parse the arguments into commands.
Unusable in its current form because it only deals with commands, not
operators. What might be useful though:

- For Minishell we will also have to store commands in variables
- I keep hearing the term 'builtins' when people talk about Minishell.
	I wonder if that has anything to do with us accessing certain commands
	differently based on whether they are builtins or not? Could be usable for
	establishing whether something is a builtin or not?
	- sed command probably also an edge case for minishell (this is what is 
	being handlde in get_commands)
*/

static int	try_pathname(char *path, t_cmd *cmd)
{
	char	*pathslash;

	pathslash = ft_strjoin(path, "/");
	if (!pathslash)
		return (1);
	cmd->pathname = ft_strjoin(pathslash, cmd->cmdv[0]);
	free(pathslash);
	if (!cmd->pathname)
		return (1);
	if (access(cmd->pathname, F_OK))
	{
		free(cmd->pathname);
		cmd->pathname = NULL;
		return (1);
	}
	else
		return (0);
}

static int	get_pathname(char **paths, t_cmd *cmd)
{
	int		i;
	int		not_found;

	i = 0;
	not_found = 1;
	cmd->pathname = NULL;
	if (!access(cmd->cmdv[0], F_OK))
	{
		cmd->pathname = ft_strdup(cmd->cmdv[0]);
		return (0);
	}
	else if (!paths)
		return (1);
	while (not_found > 0 && paths[i])
	{
		not_found = try_pathname(paths[i], cmd);
		i++;
	}
	return (not_found);
}

static void	get_paths(t_pipex *pipex, char **envp, char c)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!*envp)
		return ;
	pipex->paths = ft_split(*envp + 5, c);
	if (!pipex->paths)
		exit_pipex(pipex, 1, "Malloc failure getting env paths");
}

static int	prep_commands(char *str, t_cmd *cmd)
{
	int		i;
	char	*tmp;

	cmd->cmdv = ft_split(str, ' ');
	if (!cmd->cmdv)
		return (1);
	if (ft_strlen(cmd->cmdv[0]) < 3 || nr_strings(cmd->cmdv) < 1)
		return (0);
	i = 1;
	if (!ft_strncmp(cmd->cmdv[0] + (ft_strlen(cmd->cmdv[0]) - 3), "sed", 3))
	{
		while (cmd->cmdv[i])
		{
			if (cmd->cmdv[i][0] == '\'')
			{
				tmp = ft_strdup(cmd->cmdv[i]); //kinda silly that i strdup and then strtrim here. Should just count chars until ' and then strndup. or maybe there's a reason i did it like this? check out later
				free(cmd->cmdv[i]);
				cmd->cmdv[i] = ft_strtrim(tmp, "\'");
				free(tmp);
			}
			i++;
		}
	}
	return (0);
}

int	get_commands(t_pipex *pipex, char **argv, char **envp)
{
	int	found;
	int	offset;

	get_paths(pipex, envp, ':');
	if (pipex->here_doc)
		offset = 3;
	else
		offset = 2;
	while (pipex->current_child < pipex->nr_children)
	{
		if (!argv || !argv[pipex->current_child + offset])
			exit_pipex(pipex, 1, "Unable to grab arguments");
		if (prep_commands(argv[pipex->current_child + offset], \
		&pipex->cmd[pipex->current_child]))
			exit_pipex(pipex, 1, "Malloc failure");
		found = get_pathname(pipex->paths, &pipex->cmd[pipex->current_child]);
		if (found > 0)
			pipex->cmd[pipex->current_child].pathname = NULL;
		else if (found < 0)
			exit_pipex(pipex, 1, "Malloc failure");
		pipex->current_child++;
	}
	pipex->current_child = 0;
	return (0);
}
