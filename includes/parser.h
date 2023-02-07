/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/02/03 18:31:07 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include <stdio.h>

/**
 * Redirection type enum.
 * 	- red. input
 * 	- here_doc
 * 	- red. output
 * 	- red. output append
*/

typedef enum e_red_type
{
	DEFAULT,
	RED_IPUT,
	HERE_DOC,
	RED_OPUT,
	RED_OPUT_A
}	t_red_type;

/**
 * Redirection data:
 * 	- redirection type
 * 	- file name
 * 	- here_doc (file descriptor)
 * 	- next command (next here_doc or NULL)
*/

typedef struct s_red
{
	t_red_type		type;
	char			*filename;
	int				fd;
}	t_red;

/**
 * Command data: 
 * 	- execution info
 * 	- input (can be NULL)
 *  - output (can be NULL)
 *  - next command (pipes or NULL) <-- removed this b/c information about pipe will be added to the cmd info itself
*/

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				argc;
	t_red			in;
	t_red			out;
	struct s_cmd	*next;
}	t_cmd;

void		parser(t_token *token, t_cmd **cmd);
void		init_parser(t_cmd **cmd);
t_token		*parse_command(t_token *tmp_token, t_cmd *cmd);
t_token		*parse_pipe(t_token *tmp_token, t_cmd *cmd);

#endif