/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:51:31 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 14:51:33 by abeznik       ########   odam.nl         */
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
	RED_IPUT,
	HERE_DOC,
	RED_OPUT,
	RED_OPUT_A
}	t_red_type;

/**
 * Redirection data:
 * 	- redirection type
 * 	- file name
 * 	- file descriptor
 * 	- next redirection data
*/

typedef struct s_red
{
	t_red_type		type;
	char			*filename;
	int				fd;
	struct s_red	*next;
}	t_red;

/**
 * Cmd data:
 *  - argv
 * 
 */
typedef struct s_cmd
{
	char			**argv;
	int				argc;
	t_red			*in;
	t_red			*out;
	struct s_cmd	*next;
}	t_cmd;

bool	parser(t_token *token, t_cmd **cmd);
bool	parse_args(t_token **token, t_cmd *cmd);
bool	parse_redir(t_token **token, t_cmd *cmd);
bool	parse_pipe(t_token **token, t_cmd **cmd);

/**
 * Syntax grammar rules
 */

bool	syntax_red(t_token *token);
bool	syntax_pipe(t_token *token);
bool	error_msg(char *msg);

/**
 * Command node utils
 */
t_cmd	*cmd_new(void);
t_cmd	*cmd_last(t_cmd	*cmd);
bool	cmd_append(t_cmd **cmd, t_cmd *new);
void	cmdclear(t_cmd **cmd, void (*del)(void*));
void	cmd_delone(t_cmd *cmd, void (*del)(void*));

/**
 * Redirection node utils
 */

t_red	*red_new(t_red_type type);
t_red	*red_last(t_red	*red);
bool	red_append(t_red **red, t_red *new);
void	redclear(t_red **red, void (*del)(void*));
void	red_delone(t_red *red, void (*del)(void*));

#endif
