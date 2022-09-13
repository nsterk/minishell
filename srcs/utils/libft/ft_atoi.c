/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 19:02:41 by nsterk        #+#    #+#                 */
/*   Updated: 2021/06/25 00:47:12 by naomisterk    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	ull_overflow(int negative,
				unsigned long long num, const char *str)
{
	if (negative == -1 && *str > 5)
		return (0);
	if (negative == 1 && *str > 5)
		return (-1);
	num = (num * 10) + (*str - '0');
	return (num);
}

static int	ll_overflow(int negative,
					unsigned long long num, const char *str)
{
	if (negative == -1 && *str > 8)
		return (0);
	if (negative == 1 && *str > 7)
		return (-1);
	num = (num * 10) + (*str - '0');
	return (num * negative);
}
*/
int	ft_atoi(const char *str)
{
	int	num;
	int	new_num;
	int	negative;

	num = 0;
	negative = 1;
	if (*str == '\0')
		return (0);
	str = ft_skipspace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		new_num = (num * 10) + (*str - '0');
		if (new_num < num)
			return (0);
		num = new_num;
		str++;
	}
	return (num * negative);
}
