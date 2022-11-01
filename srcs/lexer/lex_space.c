/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_space.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:52:09 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/01 20:56:25 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_space(t_lexer *lexer, t_toktype type)
{
	if (lexer && type < TOK_MAX)
		printf("lex_space works!\n");
	return (true);
}
