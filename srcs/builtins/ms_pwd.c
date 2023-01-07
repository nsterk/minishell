/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:15:07 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 13:32:32 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exec_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		perror("");
		exit(3000);
	}
	else
		ft_putendl_fd(str, STDOUT_FILENO);
	free(str);
	return (EXIT_SUCCESS);
}
