/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 21:24:38 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/12 18:34:09 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief duplicates a string on the heap
 * 
 * @param src 
 * @return char* 
 */
char	*ft_strdup(const char *src)
{
	char	*rstr;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen((char *)src);
	rstr = ft_calloc(len + 1, sizeof(*rstr));
	if (!rstr)
		return (NULL);
	rstr = ft_strcpy(rstr, (char *)src);
	return (rstr);
}
