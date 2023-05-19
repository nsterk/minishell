/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 20:36:55 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/05 14:31:44 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dptr;
	char	*sptr;
	size_t	i;

	dptr = (char *)dst;
	sptr = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (sptr < dptr)
	{
		while (len > 0)
		{
			dptr[len - 1] = sptr[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dptr, sptr, len);
	return (dptr);
}
