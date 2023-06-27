
#ifndef EXPANDER_H
# define EXPANDER_H

# include "lexer.h"

typedef struct s_expander
{
	t_expansion	*exp;
	size_t		pos;
	char		**envp;
	pid_t		*status;
}	t_expander;

bool		expander(t_expander *expander, t_lexer *lexer);
// char		*expand_exit_status(t_expander *expander, t_token *token);
bool		do_expanding(t_expander *expr, t_token *token);
// bool		do_expanding(t_token *token, t_expansion *exp, size_t *pos, char **envp);
// t_token		*clean_token(t_lexer *lex, t_token **token);
void		get_param(t_expander *expr, t_token *token);
t_token		*split_words(t_token **token);
bool		contains_space(char *str);
void		rm_tokenspace(t_lexer *lexer);
// void		env_not_found(t_token *token, t_expander *expander);

#endif
