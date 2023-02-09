/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 19:58:52 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/02/09 20:56:48 by nsterk        ########   odam.nl         */
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
t_token		*init_cmd(t_token *token, t_cmd *cmd, int argc);
t_token		*parse_command(t_token *token, t_cmd **cmd);
t_token		*parse_pipe(t_token *token, t_cmd *cmd);

/*	PARSER UTILS	*/
t_cmd		*cmd_new(char *str);
t_cmd		*cmd_last(t_cmd	*cmd);
int			cmd_append(t_cmd **cmd, t_cmd *new);
void		cmdclear(t_cmd **cmd, void (*del)(void*));
void		cmd_delone(t_cmd *cmd, void (*del)(void*));

#endif