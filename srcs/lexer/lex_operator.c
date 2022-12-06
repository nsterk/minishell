/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_operator.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:51:55 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/06 21:57:28 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_operator(t_lexer *lex, t_toktype type)
{
	const size_t	start = lex->idx;

	if (type != TOK_PIPE && lex->str[lex->idx] == lex->str[lex->idx + 1])
	{
		lex->flags |= F_EXPAND;
		lex->idx++;
	}
	delimit_token(lex, start, type);
	switch_state(lex, get_state(lex->str[lex->idx + 1]));
	return (true);
}
