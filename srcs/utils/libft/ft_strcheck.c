/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcheck.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 18:12:37 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/29 18:12:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcheck(char const *s, int (*f)(int))
{
	int	i;

	if (!s || !f)
		return (EXIT_FAILURE);
	i = 0;
	while (s[i])
	{
		if (!f(s[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
