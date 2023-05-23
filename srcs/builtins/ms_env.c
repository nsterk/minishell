
#include "builtins.h"
// #include "../../includes/builtins.h" // ? I need this on my mac

int	exec_env(char **envp, t_data_exe *data_exe)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	data_exe->last_pid = 0;
	return (EXIT_SUCCESS);
}
