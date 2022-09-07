/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:50:15 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/07 15:05:26 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (neg * nb);
}
