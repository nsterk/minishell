/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/22 16:42:41 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/03 01:45:21 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	if (*haystack == 0 || ft_strlen(needle) > len)
		return (NULL);
	i = 0;
	while (*haystack && i <= (len - needle_len))
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
