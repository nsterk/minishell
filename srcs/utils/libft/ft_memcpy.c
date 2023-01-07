/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 20:36:55 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/07 14:06:05 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dptr);
}
