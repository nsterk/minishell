/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/02/03 18:30:57 by nsterk        ########   odam.nl         */
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
# include "utils.h"

typedef struct s_data
{
	t_lexer	lexer;
	t_token	*tokens;
	t_cmd	*cmd;
}	t_data;

int				main(void);

/**
 * Init functions.
 */

void			init_data(t_data *data);
void			reinit_data(t_data *data);
void			init_lexer(t_lexer *lexer);
void			reinit_lexer(t_lexer *lexer);
void			init_parser(t_cmd **cmd);

#endif