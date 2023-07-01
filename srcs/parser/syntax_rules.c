/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_rules.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:27:07 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/01 16:12:46 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

bool	syntax_red(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	if (!tmp->next)
		return (error_msg("syntax error near unexpected token 'newline'"));
	if (tmp->next->flags & F_SPACE)
		tmp = tmp->next;
	if (!tmp->next)
		return (error_msg("syntax error near unexpected token 'newline'"));
	if (tmp->next->flags & F_OPERATOR)
		return (error_msg("syntax error near unexpected token 'operator'"));
	return (false);
}

bool	syntax_pipe(t_token *token)
{
	if (!token || !token->next || token->next->type == TOK_PIPE)
		return (error_msg("syntax error near unexpected token '|'"));
	return (false);
}

bool	error_msg(char *msg)
{
	printf("momoshell: %s\n", msg);
	return (true);
}
