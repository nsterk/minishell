/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2023/03/31 21:32:25 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "test.h"

static t_toktype	s_get_type(t_lexstate state)
{
	static const t_toktype	s_type[] = {
	[S_SPACE] = TOK_SPACE,
	[S_REDIR_IN] = TOK_REDIR_IN,
	[S_REDIR_OUT] = TOK_REDIR_OUT,
	[S_PIPE] = TOK_PIPE,
	[S_WORD] = TOK_WRD,
	[S_DQUOTE] = TOK_WRD,
	[S_SQUOTE] = TOK_WRD,
	[S_EOF] = TOK_EOF
	};

	return (s_type[state]);
}

static bool	s_lexfunction(t_lexer *lexer, t_toktype type)
{
	static const t_lexfunction lex[] = {
		[TOK_SPACE] = &lex_space,
		[TOK_WRD] = &lex_word,
		[TOK_REDIR_IN] = &lex_operator,
		[TOK_REDIR_OUT] = &lex_operator,
		[TOK_PIPE] = &lex_operator
	};
	return (lex[type](lexer, type));
}

bool	lexer(t_lexer *lexer)
{
	lexer->state = get_state(lexer->str[0]);
	while (lexer->state != S_EOF)                                                                       
	{
		if (s_lexfunction(lexer, s_get_type(lexer->state)))
		{
			//cleany clean
			return (true);
		}	
	}
	return (false);
}

void	delimit_token(t_lexer *lexer, size_t start, t_toktype type)
{
	t_token	*new;

	new = token_new(type, lexer->state, \
		ft_strndup(lexer->str + start, lexer->idx - start + 1));
	if (!new)
		exit(EXIT_FAILURE);
	new->flags = lexer->flags;
	if (token_append(&(lexer->tokens), new))
		exit(EXIT_FAILURE);
}
