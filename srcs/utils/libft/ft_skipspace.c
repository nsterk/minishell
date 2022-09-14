/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipspace.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 18:59:59 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/03 07:40:54 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skipspace(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v' || *str == ' ')
		str++;
	return (str);
}
