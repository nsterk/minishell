/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/22 09:36:19 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/24 16:24:25 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strccpy(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != c)
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
