/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:35:57 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/12 23:29:04 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	close_pipe(int *fd)
{
	if (!fd)
		return ;
	close(fd[0]);
	close(fd[1]);
}

void	open_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nr_children - 1)
	{
		if (pipe(pipex->fd[i]) == -1)
			exit_pipex(pipex, 1, "Failure opening pipe");
		i++;
	}
}

/*
I had this eureka moment where I figured that this was THE way to handle closing pipes in children.
But then I lost the eureka moment at some point. Still think there is something to this simple solution but need to look at it again.
*/

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nr_children - 1)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		i++;
	}
}
