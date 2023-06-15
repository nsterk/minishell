
#include "minishell.h"
#include "test.h"

static bool	s_parse_command(t_token **token, t_cmd **cmd);

bool	parser(t_token *token, t_cmd **cmd)
{
	t_token	*tmp;

	tmp = token;
	*cmd = cmd_new();
	check_malloc(*cmd, "parser");
	while (tmp)
	{
		if (tmp->type == TOK_SPACE)
			tmp = tmp->next;
		if (s_parse_command(&tmp, cmd))
			return (true);
	}
	// print_tbl(*cmd);
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

bool	error_msg(char *msg)
{
	printf("momoshell: %s\n", msg);
	return (true);
}
