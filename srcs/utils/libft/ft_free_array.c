/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 15:44:37 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/02 12:24:40 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return (1);
}
