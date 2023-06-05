
#include "lexer.h"

bool	lex_space(t_lexer *lexer, t_toktype type)
{
	t_token	*new;

	while (lexer->state == get_state(lexer->str[lexer->idx + 1]))
		lexer->idx++;
	new = ft_calloc(1, sizeof(t_token));
	check_malloc(new, "lex_space");
	new->prev = NULL;
	new->next = NULL;
	new->word = NULL;
	new->exp_count = 0;
	new->type = type;
	new->state = S_SPACE;
	if (token_append(&(lexer->tokens), new))
		exit(EXIT_FAILURE);
	switch_state(lexer, get_state(lexer->str[lexer->idx + 1]));
	return (false);
}
