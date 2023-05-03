/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:04:12 by nsterk        #+#    #+#                 */
/*   Updated: 2023/05/03 12:57:59 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			new->exp[exp_count - 1].parameter = NULL;
			new->exp[exp_count - 1].start = 0;
			new->exp[exp_count - 1].end = 0;
			exp_count--;
		}
	}
	return (new);
}

t_token	*token_new(t_toktype type, t_lexstate state, char *str, size_t exps)
{
	t_token	*new;

	if (!str)
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

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argc = 0;
	cmd->args = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_red	*red_new(t_red_type type)
{
	t_red	*red;

	red = malloc(sizeof(t_red));
	if (!red)
		return (NULL);
	red->type = type;
	red->fd = -1; //dunno why i'm initing it to -1 maybe change later
	red->filename = NULL;
	red->next = NULL;
	return (red);
}
