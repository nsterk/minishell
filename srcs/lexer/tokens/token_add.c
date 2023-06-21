
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
			new->exp[exp_count - 1].parameter = NULL;
			new->exp[exp_count - 1].start = 0;
			new->exp[exp_count - 1].end = 0;
			exp_count--;
		}
	}
	return (new);
}

int	token_append(t_token **token, t_token *new)
{
	t_token	*tail;

	if (!token || !new)
		return (1);
	if (*token == NULL)
		*token = new;
	else
	{
		tail = token_last(*token);
		new->prev = tail;
		tail->next = new;
	}
	return (0);
}

int	token_addafter(t_token **spot, t_token *new)
{
	t_token	*next;

	if (!spot || !(*spot) || !new)
		return (1);
	next = (*spot)->next;
	new->prev = *spot;
	(*spot)->next = new;
	new->next = next;
	if (next)
		next->prev = new;
	return (0);
}
