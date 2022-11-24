/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 12:07:14 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 12:07:44 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_check_malloc(void *ptr, char *func)
{
	if (!ptr)
	{
		errno = ENOMEM;
		exit_error(errno, func, NULL);
	}
	return ;
}
