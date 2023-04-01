/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/04/01 01:07:55 by nsterk        ########   odam.nl         */
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
# include "lexer.h"
# include "parser.h"
# include "utils.h"

typedef struct s_data
{
	t_lexer	lexer;
	t_cmd	*cmd;
	char	**envp;
	int		last_pid;
}	t_data;

int			main(void);
int			prompt(t_lexer *lexer);
void		exit_minishell(int status, char *msg);

/**
 * Init functions.
 */

void		init_data(t_data *data);
void		reinit_data(t_data *data);
void		init_lexer(t_lexer *lexer);
void		reinit_lexer(t_lexer *lexer);

#endif