/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 15:06:30 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/07 15:05:26 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
