/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   squote.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 21:53:13 by nsterk        #+#    #+#                 */
/*   Updated: 2022/10/20 19:34:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
// #include "utils.h"

char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

static void	single_quotes(char *str)
{
	size_t	i;
	size_t	start;
	char	*tmp;

	start = 1;
	i = 0;
	while (str[i] && str[i] != '\'')
		i++;
	if (str[i] != '\'')
		printf("unclosed quote\n");
	else
	{
		tmp = ft_substr(str, 1, i - 1);
		printf("%s\n", tmp);
		free(tmp);
	}
}

int	main(void)
{
	single_quotes("\'momo is de fucking shit\'");
	single_quotes("\'momo is de fucking shit");
	return (0);
}
