/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_lexer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:57:14 by nsterk        #+#    #+#                 */
/*   Updated: 2023/05/03 13:28:22 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_lexer(t_lexer *lexer)
{
	lexer->str = NULL;
	lexer->tokens = NULL;
	lexer->idx = 0;
	lexer->expansions = 0;
	lexer->flags = 0;
}

void	reinit_lexer(t_lexer *lexer)
{
	tokenclear(&lexer->tokens, free);
	lexer->tokens = NULL;
	if (lexer->str)
		free(lexer->str);
	lexer->str = NULL;
	lexer->expansions = 0;
	lexer->idx = 0;
	lexer->flags = 0;
}
