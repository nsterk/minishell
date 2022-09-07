/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 11:03:44 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/07 15:05:26 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		buff = (char *)malloc(1);
		buff[0] = '\0';
		return (buff);
	}
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	while ((len > i) && (s[start] != '\0'))
	{
		buff[i] = s[start];
		i++;
		start++;
	}
	buff[i] = '\0';
	return (buff);
}
