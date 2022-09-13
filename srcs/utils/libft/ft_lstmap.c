/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 11:37:31 by nsterk        #+#    #+#                 */
/*   Updated: 2021/03/03 01:37:22 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*retlst;

	if (!lst || !f)
		return (NULL);
	temp = lst;
	retlst = ft_lstnew(f(temp->content));
	if (!retlst)
		return (NULL);
	temp = temp->next;
	while (temp != NULL)
	{
		new = ft_lstnew(f(temp->content));
		if (!(new))
		{
			ft_lstclear(&retlst, del);
			return (NULL);
		}
		ft_lstadd_back(&retlst, new);
		temp = temp->next;
	}
	return (retlst);
}
