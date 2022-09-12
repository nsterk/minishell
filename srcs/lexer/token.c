/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:33:41 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/12 15:56:02 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	gen_tokens(char *input)
{
	char	**token;
	int		x;

	x = 0;
	token = ft_split(input, ' ');
	if (!token)
		error_msg("Error with split.");
	while (token[x])
	{
		printf("Token: <%s>\n", token[x]);
		free(token[x]);
		x++;
	}
	free(token);
	free(input);
}
