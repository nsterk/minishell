/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/06 15:16:22 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * Needed libs.
 */
# include <unistd.h>

/**
 * Minishell libs.
 */
# include "prompt.h"
# include "lexer.h"
# include "parser.h"
# include "executor.h"
# include "builtins.h"
# include "utils.h"

typedef struct s_data
{
	t_lexer	lexer;
	t_token	*tokens;
	t_table	*table;
	char	**envp;
}	t_data;

int				main(int argc, char **argv, char **envp);

/**
 * Init functions.
 */

// void			init_data(t_data *data);
void			init_data(t_data *data, char **envp);
void			init_lexer(t_lexer *lexer);

#endif