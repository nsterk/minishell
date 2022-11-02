/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_space.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:09 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/02 16:42:24 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_space(t_lexer *lexer, t_toktype type)
{
	/**
	 * dan hier something along the lines of while new_state == state
	 * 	idx++
	 * 
	 */
	if (lexer && type < TOK_MAX)
		printf("lex_space works!\n");
	while (lexer->state == get_state(lexer->input[lexer->idx + 1]))
		lexer->idx++;
	return (true);
}
