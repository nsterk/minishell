/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 12:07:14 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/06 12:05:16 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_malloc(void *ptr, char *func)
{
	if (!ptr)
	{
		errno = ENOMEM;
		exit_error(errno, func, NULL);
	}
	return ;
}
