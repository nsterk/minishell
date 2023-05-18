
#include "minishell.h"

bool	syntax_red(t_cmd *cmd, t_token *token)
{
	(void)cmd;
	if (!token->next)
		return (error_msg("syntax error near unexpected token 'newline'"));
	return (false);
}

bool	syntax_pipe(t_cmd *cmd, t_token *token)
{
	// if (!cmd->argc)
	// 	return (error_msg("syntax error - no cmd to pipe output from"));
	if (!token || !token->next || token->next->type == TOK_PIPE)
		return (error_msg("syntax error near unexpected token '|'"));
	return (false);
}

bool	syntax_word(t_token *token)
{
	(void)token;
	return (false);
}
