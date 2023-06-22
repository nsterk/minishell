
#include "minishell.h"

static bool	s_parse_command(t_token **token, t_cmd **cmd);

bool	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	if (!token)
		return (true);
	tmp = token;
	*cmd = cmd_new();
	check_malloc(*cmd, "parser");
	while (tmp)
	{
		if (s_parse_command(&tmp, cmd))
			return (true);
	}
	return (false);
}

static bool	s_parse_command(t_token **token, t_cmd **cmd)
{
	if ((*token)->flags & F_WORD)
		return (parse_args(token, *cmd));
	if ((*token)->type == TOK_REDIR_IN || (*token)->type == TOK_REDIR_OUT)
		return (parse_redir(token, *cmd));
	if ((*token)->type == TOK_PIPE)
		return (parse_pipe(token, cmd));
	return (false);
}
