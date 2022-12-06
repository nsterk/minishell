/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_operator.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:51:55 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/06 17:40:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_operator(t_lexer *lexer, t_toktype type)
{
	if (lexer && type < TOK_MAX)
		printf("lex_operator works!\n");
	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
		lexer->idx++;
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (true);
}
