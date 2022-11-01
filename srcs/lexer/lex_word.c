/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_word.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:51 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/01 20:56:36 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_word(t_lexer *lexer, t_toktype type)
{
	if (lexer && type < TOK_MAX)
		printf("lex_word works!\n");
	return (true);
}
