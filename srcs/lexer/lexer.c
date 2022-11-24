/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/24 21:28:23 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "test.h"

static t_toktype	s_get_type(t_lexstate state)
{
	static const t_toktype	s_type[] = {
	[S_SPACE] = TOK_SPACE,
	[S_OPERATOR] = TOK_OP,
	[S_WORD] = TOK_CMD,
	[S_DQUOTE] = TOK_CMD,
	[S_SQUOTE] = TOK_CMD,
	[S_EOF] = TOK_EOF
	};

	return (s_type[state]);
}

static bool	s_lexfunction(t_lexer *lexer, t_toktype type)
{
	static const t_lexfunction lex[] = {
		[TOK_SPACE] = &lex_space,
		[TOK_CMD] = &lex_word,
		[TOK_OP] = &lex_operator
	};
	return (lex[type](lexer, type));
}

void	lexer(t_lexer *lexer)
{
	lexer->state = get_state(lexer->input[0]);
	while (lexer->state != S_EOF)
	{
		s_lexfunction(lexer, s_get_type(lexer->state));
	}
}

void	delimit_token(t_lexer *lexer, size_t start, t_toktype type)
{
	t_token	*new;

	new = token_new(start, lexer->idx, type);
	if (!new)
		exit(EXIT_FAILURE);
	new->word = ft_strndup(lexer->input + start, lexer->idx - start + 1);
	if (!new->word)
		exit(EXIT_FAILURE);
	if (token_append(&(lexer->tokens), new))
		exit(EXIT_FAILURE);
}
