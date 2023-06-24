
#include "minishell.h"

static void	st_init_envp(t_data *data, char **envp);

void	init_data(t_data *data, char **envp)
{
	init_lexer(&data->lexer);
	st_init_envp(data, envp);
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

static void	st_init_envp(t_data *data, char **envp)
{
	size_t	len;

	len = ft_array_len(envp);
	data->envp = ft_calloc(len + 1, sizeof(char *));
	check_malloc(data->envp, "st_init_envp **");
	data->envp[len] = NULL;
	len--;
	while (len + 1)
	{
		data->envp[len] = ft_strdup(envp[len]);
		check_malloc(data->envp, "st_init_envp *");
		len--;
	}
}
