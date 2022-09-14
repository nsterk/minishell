/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 20:59:45 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/13 19:47:55 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strndup(char *src, int n)
{
	char	*str;

	str = malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, n + 1);
	return (str);
}

char	*ft_strgjoin(char *s1, char *s2, int len_s2)
{
	int		len_s1;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, len_s2));
	len_s1 = ft_strlen(s1);
	str = malloc(sizeof(*str) * (len_s1 + len_s2 + 1));
	if (!str)
		str = NULL;
	else
	{
		ft_strlcpy(str, s1, len_s1 + 1);
		ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	}
	free((char *)s1);
	return (str);
}
