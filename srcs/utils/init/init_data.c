
#include "minishell.h"

void	init_data(t_data *data, char **envp)
{
	init_lexer(&data->lexer);
	init_envp(data, envp);
	data->last_pid = 0;
	init_expander(data);
	data->cmd = NULL;
}

void	init_lexer(t_lexer *lexer)
{
	lexer->str = NULL;
	lexer->tokens = NULL;
	lexer->idx = 0;
	lexer->expansions = 0;
	lexer->flags = 0;
}

void	init_expander(t_data *data)
{
	data->expander.exp = NULL;
	data->expander.pos = 0;
	data->expander.envp = data->envp;
	data->expander.status = &(data->last_pid);
}
