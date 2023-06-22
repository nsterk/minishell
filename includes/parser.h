
#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
// # include "executor.h"
# include "colours.h"
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

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				argc;
	t_red			*in;
	t_red			*out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_tbl
{
	t_cmd			*cmds;
}	t_tbl;

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
// bool	syntax_word(t_token *token);

/**
 * Command node utils
 */
t_cmd	*cmd_new(void);
t_cmd	*cmd_last(t_cmd	*cmd);
int		cmd_append(t_cmd **cmd, t_cmd *new);
void	cmdclear(t_cmd **cmd, void (*del)(void*));
void	cmd_delone(t_cmd *cmd, void (*del)(void*));

t_red	*red_new(t_red_type type);
t_red	*red_last(t_red	*red);
int		red_append(t_red **red, t_red *new);
void	redclear(t_red **red, void (*del)(void*));
void	red_delone(t_red *red, void (*del)(void*));

#endif
