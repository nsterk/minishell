/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_operator.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:23:24 by nsterk        #+#    #+#                 */
/*   Updated: 2023/06/28 18:23:26 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_operator(t_lexer *lex, t_toktype type)
{
	const size_t	start = lex->idx;
	const char		c = lex->str[lex->idx];

	if (type != TOK_PIPE && c == lex->str[lex->idx + 1])
	{
		lex->flags |= F_APPEND;
		lex->idx++;
	}
	lex->flags |= F_OPERATOR;
	delimit_token(lex, start, type);
	switch_state(lex, get_state(lex->str[lex->idx + 1]));
	return (false);
}
