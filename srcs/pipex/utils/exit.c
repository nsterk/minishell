/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 19:47:04 by nsterk        #+#    #+#                 */
/*   Updated: 2022/03/25 20:15:26 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	free_strings(char **strings, int len)
{
	while (len > 0)
	{
		len--;
		if (strings[len])
			free(strings[len]);
	}
	if (strings)
		free(strings);
}

void	free_ints(int **ints, int len)
{
	while (len > 0)
	{
		len--;
		if (ints[len])
			free(ints[len]);
	}
	if (ints)
		free(ints);
}

void	free_cmd(t_cmd *cmd)
{
	free_strings(cmd->cmdv, nr_strings(cmd->cmdv));
	if (cmd->pathname)
		free(cmd->pathname);
}

void	exit_pipex(t_pipex *pipex, int status, char *message)
{
	int	i;

	i = 0;
	while (i < pipex->nr_children)
	{
		free_cmd(&pipex->cmd[i]);
		i++;
	}
	if (pipex->pid)
		free(pipex->pid);
	if (pipex->paths)
		free_strings(pipex->paths, nr_strings(pipex->paths));
	if (pipex->fd)
		free_ints(pipex->fd, pipex->nr_children - 1);
	if (message)
		perror(NULL);
	exit(status);
}
