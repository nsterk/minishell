/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 19:38:05 by nsterk        #+#    #+#                 */
/*   Updated: 2022/11/01 19:43:10 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexstate	get_state(char c)
{
	if (c == '\0')
		return (S_EOF);
	if (c == '\'')
		return (S_SQUOTE);
	if (c == '"')
		return (S_DQUOTE);
	if (ft_isspace(c))
		return (S_SPACE);
	if (c == '<' || c == '>' || c == '|')
		return (S_OPERATOR);
	return (S_WORD);
}
