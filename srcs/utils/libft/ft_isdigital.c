/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigital.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/05 17:38:31 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/05 17:48:56 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdigital(char *str)
{
	size_t	i;

	i = 1;
	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
