/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 15:31:54 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/14 15:32:18 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strndup(char *src, size_t n)
{
	char	*str;

	str = malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, n + 1);
	return (str);
}
