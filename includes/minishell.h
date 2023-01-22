/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/22 11:53:01 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * Minishell libs.
 */
# include "prompt.h"
# include "builtins.h"
# include "executor.h"
# include "parser.h"
# include "lexer.h"
# include "utils.h"
# include "signals.h"

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
	t_token	*tokens;
	t_table	*table;
	char	**envp;
	int		last_pid;
}	t_data;

int				main(int argc, char **argv, char **envp);

/**
 * Init functions.
 */

// void			init_data(t_data *data);
void			init_data(t_data *data, char **envp);
void			init_lexer(t_lexer *lexer);

#endif