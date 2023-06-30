/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 18:15:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 18:15:56 by nsterk        ########   odam.nl         */
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
