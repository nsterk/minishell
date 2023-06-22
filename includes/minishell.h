
#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * Minishell feature libs.
 */

# include "lexer.h"
# include "expander.h"
# include "parser.h"
# include "executor.h"
# include "builtins.h"

/**
 * Minishell util libs.
 */

# include "defines.h"
# include "utils.h"
# include "signals.h"
# include "colours.h"

/**
 * Needed libs.
 */

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

// int		prompt(t_lexer *lexer);

/**
 * Init functions.
 */

void	init_data(t_data *data, char **envp);
void	reinit_data(t_data *data);
void	init_lexer(t_lexer *lexer);
void	reinit_lexer(t_lexer *lexer);

#endif
