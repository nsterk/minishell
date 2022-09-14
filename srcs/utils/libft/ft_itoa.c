/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:03:04 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/03 01:35:34 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoalen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	ft_topos(char *s, int n)
{
	s[0] = '-';
	n *= -1;
	return (n);
}

static char	*atoi_minint(char *s)
{
	char	*sptr;

	sptr = s;
	sptr[0] = '-';
	sptr[1] = '2';
	sptr[2] = '1';
	sptr[3] = '4';
	sptr[4] = '7';
	sptr[5] = '4';
	sptr[6] = '8';
	sptr[7] = '3';
	sptr[8] = '6';
	sptr[9] = '4';
	sptr[10] = '8';
	sptr[11] = '\0';
	return (sptr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*rstr;

	len = ft_itoalen(n);
	rstr = (char *)malloc(sizeof(*rstr) * (len + 1));
	if (!rstr)
		return (NULL);
	if (n == 0)
		rstr[0] = '0';
	rstr[len] = '\0';
	if (n == -2147483648)
	{
		rstr = atoi_minint(rstr);
		return (rstr);
	}
	if (n < 0)
		n = ft_topos(rstr, n);
	while (n != 0 && len >= 0)
	{
		rstr[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (rstr);
}
