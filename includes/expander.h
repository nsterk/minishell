
#include "lexer.h"

bool		expander(char **envp, t_lexer *lex);
bool		do_expanding(t_token *token, t_expansion *exp, size_t *pos, char **envp);
t_token		*split_words(t_token **token);
bool		contains_space(char *str);
