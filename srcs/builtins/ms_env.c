
#include "builtins.h"

int	exec_env(char **envp, t_data *data)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	data->last_pid = 0;
	return (EXIT_SUCCESS);
}
