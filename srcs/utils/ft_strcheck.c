/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcheck.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 10:10:00 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/22 10:10:10 by arthurbezni   ########   odam.nl         */
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
