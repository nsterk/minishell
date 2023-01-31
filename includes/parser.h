/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/31 22:21:51 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include <stdio.h>

typedef struct s_io
{
	int		fd;
	char	*filename;
}	t_io;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
}	t_cmd;

typedef struct s_table
{
	t_cmd	*cmd;
	t_io	*in;
	t_io	*out;
}	t_table;

t_table		*parser(t_token *token);
void		parse_command(t_token *token, t_table *table);
void		parse_pipe(t_token *token, t_table *table);

#endif