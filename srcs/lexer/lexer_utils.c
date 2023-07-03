/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:18:45 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/03 15:13:14 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delimit_token(t_lexer *lex, size_t start, t_toktype type)
{
	t_token	*new;

	new = token_new(type, lex->state, \
		ft_strndup(lex->str + start, lex->idx - start + 1), lex->expansions);
	check_malloc(new, "delimit_token");
	new->flags = lex->flags;
	if (type == TOK_WRD)
		new->flags |= F_WORD;
	if (lex->flags & F_FILENAME)
		new->filename = true;
	if (token_append(&(lex->tokens), new))
		exit(EXIT_FAILURE);
	lex->expansions = 0;
	lex->flags = 0;
}

void	switch_state(t_lexer *lexer, t_lexstate new_state)
{
	lexer->state = new_state;
	lexer->idx++;
}

t_lexstate	get_state(int c)
{
	if (c == '\0')
		return (S_EOF);
	if (ft_isspace(c))
		return (S_SPACE);
	if (c == CH_SQUOTE)
		return (S_SQUOTE);
	if (c == CH_DQUOTE)
		return (S_DQUOTE);
	if (c == CH_LESS)
		return (S_REDIR_IN);
	if (c == CH_GREAT)
		return (S_REDIR_OUT);
	if (c == CH_PIPE)
		return (S_PIPE);
	return (S_WORD);
}
