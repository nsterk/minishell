/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/04/22 16:41:17 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * Minishell libs.
 */
// # include "prompt.h"
# include "builtins.h"
# include "executor.h"
# include "parser.h"
# include "lexer.h"
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

typedef struct s_data
{
	t_lexer	lexer;
	t_cmd	*cmd;
	char	**envp;
	int		last_pid;
}	t_data;

int			prompt(t_lexer *lexer);

/**
 * Error functions.
 */
bool		error_msg(char *msg);

/**
 * Init functions.
 */

void		init_data(t_data *data, char **envp);
void		reinit_data(t_data *data);
void		init_lexer(t_lexer *lexer);
void		reinit_lexer(t_lexer *lexer);

#endif