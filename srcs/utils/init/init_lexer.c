/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_lexer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:57:14 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/01 18:28:14 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_lexer(t_lexer *lexer)
{
	lexer->input = NULL;
	lexer->tokens = NULL;
	lexer->idx = 0;
}
