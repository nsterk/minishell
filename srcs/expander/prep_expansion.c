
#include "minishell.h"

static int		st_prep_token(t_token *token);
static int		st_find_end(t_token *token, size_t i, size_t *pos);

int	prep_expansion(t_lexer *lex)
{
	t_token	*tmp;

	tmp = lex->tokens;
	while (tmp)
	{
		if (st_prep_token(tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		st_prep_token(t_token *token)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	while (i < token->exp_count)
	{
		while (token->word[pos])
		{
			if (token->word[pos] == CH_EXPAND)
			{
				if (st_find_end(token, i, &pos))
					return (1);
				break ;
			}
			pos++;
		}
		// printf("exp[%zu].start: %zu	exp[%zu].end: %zu	exp[%zu].param: %s\n", i, token->exp[i].start, i, token->exp[i].end, i, token->exp[i].parameter);
		i++;
	}
	return (0);
}

static int	st_find_end(t_token *token, size_t i, size_t *pos)
{
	t_expansion	*exp;

	exp = &(token->exp[i]);
	exp->start = *pos;
	(*pos)++;
	if (ft_isdigit(token->word[*pos]))
		exp->end = *pos;
	else
	{
		while (token->word[*pos] != CH_EXPAND && get_state(token->word[*pos]) == S_WORD)
			(*pos)++;
		exp->end = *pos - 1;
	}
	exp->parameter = ft_strndup(token->word + exp->start + 1, exp->end - exp->start);
	if (!(exp->parameter))
		return (1);
	return (0);
}
