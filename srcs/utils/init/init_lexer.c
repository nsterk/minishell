/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_lexer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:57:14 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/15 18:02:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_lexer(t_lexer *lexer)
{
	lexer->input = NULL;
	lexer->tokens = NULL;
}
