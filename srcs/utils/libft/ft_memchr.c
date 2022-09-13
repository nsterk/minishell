/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:05:46 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/14 23:01:52 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;
	unsigned char	uc;

	sptr = (unsigned char *)s;
	uc = (unsigned char)c;
	if (!n || (uc == '\0' && (n < (size_t)ft_strlen(s))))
		return (NULL);
	while (n)
	{
		if (*sptr == uc)
			return (sptr);
		sptr++;
		n--;
	}
	return (NULL);
}
