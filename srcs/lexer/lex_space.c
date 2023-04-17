/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_space.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:09 by nsterk        #+#    #+#                 */
/*   Updated: 2023/04/01 20:26:03 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_space(t_lexer *lexer, t_toktype type)
{
	(void)type;
	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
		lexer->idx++;
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
