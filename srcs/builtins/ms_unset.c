
#include "builtins.h"
// #include "../../includes/builtins.h"

static char	**st_edit_envp_unset(char **envp, int exl_row, int size_old_envp)
{
	char	**new_envp;
	int		envp_i;
	int		new_envp_i;

	new_envp = (char **)malloc((size_old_envp) * sizeof(char *));
	check_malloc(new_envp, "edit_envp_unset");
	envp_i = 0;
	new_envp_i = 0;
	while (envp[envp_i])
	{
		if (envp_i == exl_row)
		{
			envp_i++;
			continue ;
		}
		copy_line_envp(new_envp, envp, new_envp_i, envp_i);
		envp_i++;
		new_envp_i++;
	}
	new_envp[new_envp_i] = NULL;
	ft_free_array(envp);
	return (new_envp);
}

static char	**st_ms_unset(char *arg, char **envp, t_data_exe *data_exe)
{
	int		exl_row;
	int		size_old_envp;
	char	**new_envp;

	exl_row = search_envp(arg, envp, data_exe, '=');
	if (exl_row == -1)
		return (envp);
	size_old_envp = 0;
	while (envp[size_old_envp])
		size_old_envp++;
	new_envp = st_edit_envp_unset(envp, exl_row, size_old_envp);
	check_malloc(new_envp, "ft_unset");
	data_exe->last_pid = 0;
	return (new_envp);
}

int	exec_unset(char **args, t_data_exe *data_exe)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_for_error(args[i], UNSET, data_exe->envp))
			error_message(args[i], data_exe);
		else
			data_exe->envp = st_ms_unset(args[i], data_exe->envp, data_exe);
		i++;
	}
	return (EXIT_SUCCESS);
}
