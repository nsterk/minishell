/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 11:04:23 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/07 15:05:26 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
