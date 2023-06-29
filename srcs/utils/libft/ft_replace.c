/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_replace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 18:11:30 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 18:13:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*clean_replace(char *dst, char *src, char *front, char *back)
{
	if (dst)
		free(dst);
	if (src)
		free(src);
	if (front)
		free(front);
	if (back)
		free(back);
	return (NULL);
}

char	*ft_replace(char *dst, char *src, size_t start, size_t end)
{
	char	*front;
	char	*back;

	front = NULL;
	back = NULL;
	if (!dst)
		return (clean_replace(dst, src, front, back));
	front = ft_substr(dst, 0, start);
	if (!front)
		return (clean_replace(dst, src, front, back));
	if (src)
	{
		front = strjoin_free(front, src);
		if (!front)
			return (clean_replace(dst, src, front, back));
	}
	back = ft_substr(dst, end + 1, ft_strlen(dst) - end);
	if (!back)
		return (clean_replace(dst, src, front, back));
	front = strjoin_free(front, back);
	if (!front)
		return (clean_replace(dst, src, front, back));
	free(dst);
	return (front);
}
