/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:22 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/19 20:21:48 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst)
		return (1);
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
	return (0);
}

void	token_append(t_token **token, t_token *new)
{
	t_token	*tail;

	if (!token || !new)
		return ;
	if (*token == NULL)
		*token = new;
	else
	{
		tail = token_last(*token);
		new->prev = tail;
		tail->next = new;
	}
}

int	token_addafter(t_token **spot, t_token **new)
{
	t_token	*prev;
	t_token	*next;

	if (!spot || !(*spot) || !new || !(*new))
		return (1);
	if ((*spot)->next == NULL)
	prev = *spot;
	next = prev->next;
	(*new)->prev = prev;
	(*new)->next = next;
	next->prev = *new;
	prev->next = *new;
	return (0);
}
