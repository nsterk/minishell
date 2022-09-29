/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:17:02 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:43:46 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	tokensize(t_token *token)
// {
// 	int		i;

// 	i = 0;
// 	while (token)
// 	{
// 		token = token->next;
// 		i++;
// 	}
// 	return (i);
// }
