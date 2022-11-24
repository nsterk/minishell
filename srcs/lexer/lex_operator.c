/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_operator.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:51:55 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/02 23:11:09 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_operator(t_lexer *lexer, t_toktype type)
{
	if (lexer && type < TOK_MAX)
		printf("lex_operator works!\n");
	while (lexer->state == get_state(lexer->input[lexer->idx + 1]))
		lexer->idx++;
	switch_state(lexer, get_state(lexer->input[lexer->idx + 1]));
	return (true);
}
