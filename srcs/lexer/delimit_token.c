
#include "minishell.h"

void	delimit_token(t_lexer *lex, size_t start, t_toktype type)
{
	t_token	*new;

	printf("expansions: %zu\n", lex->expansions);
	new = token_new(type, lex->state, \
		ft_strndup(lex->str + start, lex->idx - start + 1), lex->expansions);
	check_malloc(new, "delimit_token");
	new->flags = lex->flags;
	if (token_append(&(lex->tokens), new))
		exit(EXIT_FAILURE);
	lex->expansions = 0;
}
