/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:22 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 17:41:12 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

// int	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*current;

// 	if (!lst)
// 		return (1);
// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		current = ft_lstlast(*lst);
// 		current->next = new;
// 	}
// 	return (0);
// }

// void	token_append(t_token **token, t_token *new)
// {
// 	t_token	*tail;

// 	if (!token || !new)
// 		return ;
// 	if (*token == NULL)
// 		*token = new;
// 	else
// 	{
// 		tail = token_last(*token);
// 		new->prev = tail;
// 		tail->next = new;
// 	}
// }

// int	token_addafter(t_token **spot, t_token *new) //! this is really ugly and unoptimized but it works
// {
// 	t_token	*prev;
// 	t_token	*next;

// 	if (!spot || !(*spot) || !new)
// 		return (1);
// 	next = (*spot)->next;
// 	prev = (*spot)->prev;
// 	new->prev = *spot;
// 	if ((*spot)->next == NULL)
// 	{
// 		(*spot)->next = new;
// 		return (0);
// 	}
// 	new->next = next;
// 	next->prev = new;
// 	prev->next = new;
// 	return (0);
// }
