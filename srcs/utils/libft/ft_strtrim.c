/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:10:11 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 12:31:14 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rstr;
	size_t	end;

	if (!s1)
		return (NULL);
	if (s1 && !set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	rstr = ft_substr(s1, 0, end + 1);
	return (rstr);
}
