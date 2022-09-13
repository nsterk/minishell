/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_01.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/22 15:39:01 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/13 03:10:51 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int		ft_strlen(const char *s);
// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (s)
// 	{
// 		while (s[i] != '\0')
// 			i++;
// 	}
// 	return (i);
// }

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(*str) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	return (str);
}

// int	nr_strings(char **strings)
// {
// 	int	i;

// 	i = 0;
// 	if (strings && *strings)
// 	{
// 		while (strings[i])
// 			i++;
// 	}
// 	return (i);
// }

int	ft_strncmp(const char *s1, const char *s2, int len)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < len && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
