/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strjoin_free.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 18:15:05 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 18:15:06 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (str)
	{
		ft_memcpy(str, s1, len1);
		ft_memcpy(str + len1, s2, len2);
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
