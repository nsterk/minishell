/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 14:39:05 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/03 01:43:53 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char c))
{
	char			*sptr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	sptr = (char *)malloc(sizeof(*sptr) * (ft_strlen(s) + 1));
	if (!sptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		sptr[i] = f(i, s[i]);
		i++;
	}
	sptr[i] = '\0';
	return (sptr);
}
