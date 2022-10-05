/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/10/05 17:44:34 by abeznik       ########   odam.nl         */
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
# include "executor.h"

typedef struct s_data
{
	t_lexer	lexer;
	t_token	*tokens;
	t_table	*table;
}	t_data;

int				main(void);

#endif