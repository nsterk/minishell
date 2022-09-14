/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 21:24:38 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/14 16:55:37 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *src)
{
	char	*rstr;
	size_t	len;

	len = ft_strlen((char *)src);
	rstr = (char *)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	rstr = ft_strcpy(rstr, src);
	return (rstr);
}
