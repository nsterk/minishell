/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/01 21:04:30 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "test.h"

static const t_toktype	s_type[] = {
	[S_SPACE] = TOK_SPACE,
	[S_OPERATOR] = TOK_OP,
	[S_WORD] = TOK_CMD,
	[S_DQUOTE] = TOK_CMD,
	[S_SQUOTE] = TOK_CMD,
	[S_EOF] = TOK_EOF	
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
	s_lexfunction(lexer, s_type[lexer->state]);
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