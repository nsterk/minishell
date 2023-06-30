/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:46:47 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:46:48 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_pwd(t_data *data)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		perror("");
		data->last_pid = errno;
		exit(errno);
	}
	else
		ft_putendl_fd(str, STDOUT_FILENO);
	free(str);
	data->last_pid = 0;
	return (EXIT_SUCCESS);
}
