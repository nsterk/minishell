/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_operator.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:51:55 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/07 13:20:20 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_operator(t_lexer *lex, t_toktype type)
{
	const size_t	start = lex->idx;
	const char		c = lex->str[lex->idx];

	if (type != TOK_PIPE && c == lex->str[lex->idx + 1])
	{
		if (lex->str[lex->idx + 1] && lex->str[lex->idx + 2] == c)
			printf("syntax error\n");
		lex->flags |= F_EXPAND;
		lex->idx++;
	}
	delimit_token(lex, start, type);
	switch_state(lex, get_state(lex->str[lex->idx + 1]));
	return (true);
}
