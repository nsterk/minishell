
#include "lexer.h"
#include "test.h"

static t_toktype	s_get_type(t_lexstate state)
{
	static const t_toktype	s_type[] = {
	[S_SPACE] = TOK_SPACE,
	[S_SQUOTE] = TOK_SQUOTE,
	[S_DQUOTE] = TOK_DQUOTE,
	[S_REDIR_IN] = TOK_REDIR_IN,
	[S_REDIR_OUT] = TOK_REDIR_OUT,
	[S_PIPE] = TOK_PIPE,
	[S_WORD] = TOK_WRD,
	[S_EOF] = TOK_EOF
	};

	return (s_type[state]);
}

static bool	s_lexfunction(t_lexer *lexer, t_toktype type)
{
	static const t_lexfunction lex[] = {
		[TOK_SPACE] = &lex_space,
		[TOK_WRD] = &lex_word,
		[TOK_SQUOTE] = &lex_quote,
		[TOK_DQUOTE] = &lex_quote,
		[TOK_REDIR_IN] = &lex_operator,
		[TOK_REDIR_OUT] = &lex_operator,
		[TOK_PIPE] = &lex_operator
	};
	return (lex[type](lexer, type));
}

bool	lexer(t_lexer *lexer)
{
	while (ft_isspace(lexer->str[lexer->idx]))
		lexer->idx++;
	lexer->state = get_state(lexer->str[lexer->idx]);
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
