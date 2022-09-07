/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   messages.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 13:37:11 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/07 15:05:26 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // write

int	error_msg(char *msg)
{
	write(2, "Error\n\t", 7);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

int	success_msg(char *msg)
{
	write(2, "Success\n\t", 9);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (EXIT_SUCCESS);
}

void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}
