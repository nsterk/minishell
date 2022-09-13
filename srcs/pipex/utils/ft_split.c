/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 19:00:03 by nsterk        #+#    #+#                 */
/*   Updated: 2022/02/01 15:21:29 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**free_split(char **rstr, int len)
{
	while (len)
	{
		len--;
		free(rstr[len]);
	}
	free(rstr);
	return (NULL);
}

static char	**make_substrs(char **rstr, char const *s, char c, int len)
{
	int	i;
	int	j;

	j = 0;
	while (*s == (unsigned char)c)
		s++;
	while (j < len)
	{
		i = 0;
		while (s[i] != '\0' && s[i] != (unsigned char)c)
			i++;
		rstr[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!rstr[j])
			return (free_split(rstr, (int)j));
		ft_strlcpy(rstr[j], s, (i + 1));
		while (s[i] == (unsigned char)c)
			i++;
		s += i;
		j++;
	}
	rstr[j] = NULL;
	return (rstr);
}

static int	find_amount(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**rstr;
	int		len;

	if (!s)
		return (NULL);
	len = find_amount(s, c);
	rstr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!rstr)
		return (NULL);
	rstr = make_substrs(rstr, s, c, len);
	return (rstr);
}
