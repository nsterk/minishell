/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraylen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 20:49:11 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/15 20:50:44 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_arraylen(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}
