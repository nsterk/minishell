/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:18:38 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/28 18:18:39 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_tokenspace(t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->tokens;
	while (tmp)
	{
		if (tmp->flags & F_SPACE)
			tmp = token_remove(&(lexer->tokens), tmp);
		else
			tmp = tmp->next;
	}
}

bool	contains_space(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (len)
	{
		if (ft_isspace(str[len - 1]))
			return (true);
		len--;
	}
	return (false);
}

void	get_param(t_expander *expander, t_token *token)
{
	t_expansion	*exp;
	size_t		*pos;

	exp = expander->exp;
	pos = &(expander->pos);
	exp->start = expander->pos;
	(*pos)++;
	if (ft_isdigit(token->word[*pos]) || token->word[*pos] == '?')
		exp->end = *pos;
	else
	{
		while (token->word[*pos] != CH_EXPAND && \
			get_state(token->word[*pos]) == S_WORD)
			(*pos)++;
		exp->end = *pos - 1;
	}
	exp->param = ft_strndup(token->word + exp->start + 1, \
		exp->end - exp->start);
	check_malloc(exp->param, "st_get_param");
}
