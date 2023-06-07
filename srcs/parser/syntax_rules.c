
#include "minishell.h"

/**
 * valid scenarios:
 * 		1: token->next is space and token->next->next is word
 * 		2: token->next is word
 */
bool	syntax_red(t_cmd *cmd, t_token *token) //! no idea why i'm passing the cmd too probably need to remove
{
	t_token	*tmp;

	tmp = token;
	if (!tmp->next)
		return (error_msg("syntax error near unexpected token 'newline'"));
	if (tmp->next->flags & F_SPACE)
		tmp = tmp->next;
	if (!tmp->next)
		return (error_msg("syntax error near unexpected token 'newline'"));
	if (tmp->next->flags & F_OPERATOR)
		return (error_msg("syntax error near unexpected token 'operator'"));
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
