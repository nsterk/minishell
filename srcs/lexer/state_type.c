/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 19:38:05 by nsterk        #+#    #+#                 */
/*   Updated: 2023/05/03 12:58:53 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexstate	get_state(int c)
{
	if (c == '\0')
		return (S_EOF);
	if (c == CH_SQUOTE)
		return (S_SQUOTE);
	if (c == CH_DQUOTE)
		return (S_DQUOTE);
	if (ft_isspace(c))
		return (S_SPACE);
	if (c == CH_REDIR_IN)
		return (S_REDIR_IN);
	if (c == CH_REDIR_OUT)
		return (S_REDIR_OUT);
	if (c == CH_PIPE)
		return (S_PIPE);
	return (S_WORD);
}

void	switch_state(t_lexer *lexer, t_lexstate new_state)
{
	lexer->state = new_state;
	lexer->idx++;
}
