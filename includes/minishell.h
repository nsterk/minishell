
#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * Minishell libs.
 */

# include "builtins.h"
# include "executor.h"
# include "parser.h"
# include "lexer.h"
# include "defines.h"
# include "utils.h"
# include "signals.h"
# include "colours.h"

/**
 * Needed libs.
 */
// # include <readline/history.h>
// # include <readline/readline.h>
// # include <signal.h>

# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	t_lexer	lexer;
	t_cmd	*cmd;
	char	**envp;
	char	**paths;
	pid_t	last_pid;
}	t_data;

int		prompt(t_lexer *lexer);

/**
 * Error functions.
 */
bool	error_msg(char *msg);

/**
 * Init functions.
 */

void	init_data(t_data *data, char **envp);
void	reinit_data(t_data *data);
void	init_lexer(t_lexer *lexer);
void	reinit_lexer(t_lexer *lexer);

/**
 * Expander
 */
// bool	expander(char **envp, t_lexer *lex);
// bool	do_expanding(t_token *token, t_expansion *exp, size_t *pos, char **envp);

#endif
