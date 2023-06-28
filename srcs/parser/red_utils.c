/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   red_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:27:00 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/28 18:27:01 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_red	*red_new(t_red_type type)
{
	t_red	*red;

	red = malloc(sizeof(t_red));
	if (!red)
		return (NULL);
	red->type = type;
	red->fd = -1;
	red->filename = NULL;
	red->next = NULL;
	return (red);
}

t_red	*red_last(t_red	*red)
{
	t_red	*current;

	if (!red)
		return (NULL);
	current = red;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

bool	red_append(t_red **red, t_red *new)
{
	t_red	*tail;

	if (!red || !new)
		return (true);
	if (*red == NULL)
		*red = new;
	else
	{
		tail = red_last(*red);
		tail->next = new;
	}
	return (false);
}

void	redclear(t_red **red, void (*del)(void*))
{
	t_red	*tmp;

	if (!red)
		return ;
	while (*red)
	{
		tmp = (*red)->next;
		red_delone(*red, del);
		*red = tmp;
	}
}

void	red_delone(t_red *red, void (*del)(void*))
{
	if (!red || !del)
		return ;
	if (red->filename)
		del(red->filename);
	del(red);
}
