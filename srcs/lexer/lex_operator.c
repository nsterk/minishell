/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_operator.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 20:51:55 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/01 20:56:10 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	lex_operator(t_lexer *lexer, t_toktype type)
{
	if (lexer && type < TOK_MAX)
		printf("lex_operator works!\n");
	return (true);
}
