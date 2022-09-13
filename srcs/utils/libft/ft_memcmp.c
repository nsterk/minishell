/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 19:18:27 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/03 01:39:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1ptr;
	char	*s2ptr;
	size_t	i;

	if (!n)
		return (0);
	s1ptr = (char *)s1;
	s2ptr = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1ptr[i] == s2ptr[i])
			i++;
		else
			return ((unsigned char)s1ptr[i] - (unsigned char)s2ptr[i]);
	}
	return (0);
}
