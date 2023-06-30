/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:24:31 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/28 18:24:33 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*st_allocate_token(size_t exp_count);

t_token	*token_new(t_toktype type, t_lexstate state, char *str, size_t exps)
{
	t_token	*new;

	if (type != TOK_SPACE && !str)
		return (NULL);
	new = st_allocate_token(exps);
	new->prev = NULL;
	new->next = NULL;
	new->word = str;
	new->exp_count = exps;
	new->type = type;
	new->state = state;
	return (new);
}

static t_token	*st_allocate_token(size_t exp_count)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	check_malloc(new, "st_allocate_token");
	if (!exp_count)
		new->exp = NULL;
	else
	{
		new->exp = ft_calloc(exp_count, sizeof(t_expansion));
		check_malloc(new->exp, "st_allocate_token");
		while (exp_count)
		{
			new->exp[exp_count - 1].param = NULL;
			new->exp[exp_count - 1].start = 0;
			new->exp[exp_count - 1].end = 0;
			exp_count--;
		}
	}
	return (new);
}
