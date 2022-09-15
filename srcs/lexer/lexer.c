/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/15 20:21:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * think of making fucking wrappers for all fts that deal with malloc so we
 * can catch malloc failures accordingly and stop checking if success each time.
 * Also, it's ridiculous that I'm mallocing input from raw_input when all
 * the only difference is that whitespaces are trimmed. Might as well iterate
 * input from start to find the first non whitespace char and from end to
 * find the last non white space char and then use 
 * ft_strncmp(raw_input + start, "exit, ft_strlen(raw_input" - start - end).
 * Can avoid using malloc for this
 */

t_token	*lexer(void)
{
	t_token	*token = NULL;
	return (token);
}
