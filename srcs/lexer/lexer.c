/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/15 15:11:26 by abeznik       ########   odam.nl         */
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
};

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
		// printf("idx after lex_word call: %zu\n", lexer->idx);
	}
	token_printHtT(lexer->input, lexer->tokens);
}

/*
static void	get_token(t_lexer *lexer, t_toktype type);

void	lexer(t_lexer *lexer)
{
	t_toktype	state;

	while (lexer->input[lexer->start])
	{
		while (lexer->input[lexer->start] && ft_isspace(lexer->input[lexer->start]))
			lexer->start++;
		state = get_type(lexer->input[lexer->start]);
		get_token(lexer, state);
	}
}

static void	get_token(t_lexer *lexer, t_toktype type)
{
	size_t	i;

	i = 0;
	while (get_type(lexer->input[lexer->start + i]) == type)
		i++;
	if (token_append(&(lexer->tokens), token_new2(lexer->start, lexer->start + i, type)))
		exit(EXIT_FAILURE); //!malloc protection
	lexer->start += i;
}
*/