
#include "minishell.h"

static void	st_init_envp(t_data *data, char **envp);

void	init_data(t_data *data, char **envp)
{
	init_lexer(&data->lexer);
	st_init_envp(data, envp);
	data->last_pid = 0; // ! important
	data->cmd = NULL;
}

void	reinit_data(t_data *data)
{
	reinit_lexer(&data->lexer);
	cmdclear(&data->cmd, free);
	data->cmd = NULL;
}

static void	st_init_envp(t_data *data, char **envp)
{
	size_t	len;

	len = ft_array_len(envp);
	data->envp = ft_calloc(len + 1, sizeof(char *)); //! maybe going to want to strdup all of this so that we don't have a free error when cd is being executed
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
