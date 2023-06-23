
#ifndef EXPANDER_H
# define EXPANDER_H

# include "lexer.h"

typedef struct s_expander
{
	t_token		*token;
	t_expansion	*exp;
	size_t		pos;
	char		**envp;
	pid_t		status;
}	t_expander;

bool		expander(char **envp, t_lexer *lex);
// bool		expand_exit_status();
bool		do_expanding(t_expander *expander);
// bool		do_expanding(t_token *token, t_expansion *exp, size_t *pos, char **envp);
t_token		*split_words(t_token **token);
bool		contains_space(char *str);

#endif
