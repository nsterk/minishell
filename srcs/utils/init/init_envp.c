
#include "minishell.h"

/**
 * 
 * IF SHLVL
 *	1. Get value
 * 		If value is >= 999, new entry is just SHLVL=
 * 		If value is <0, new entry is SHLVL=0
 * 		If value contains non-digits, new entry is SHLVL=1
 *  
 * IF NO SHLVL
 * 	1. add new char * to envp: SHLVL=1
 * 
 */

static void	st_check_lvl(t_data *data, char *val, bool *found);

void	init_envp(t_data *data, char **envp)
{
	size_t	len;
	bool	found;

	found = false;
	len = ft_array_len(envp);
	data->envp = ft_calloc(len + 1, sizeof(char *));
	check_malloc(data->envp, "init_envp **");
	data->envp[len] = NULL;
	len--;
	while (len + 1)
	{
		if (!found && !ft_strncmp("SHLVL=", envp[len], 6))
			st_check_lvl(data, envp[len], &found);
		else
			data->envp[len] = ft_strdup(envp[len]);
		check_malloc(data->envp, "init_envp *");
		len--;
	}
	// st_check_lvl(data);
}

static void	st_check_lvl(t_data *data, char *val, bool *found)
{
	int		old_lvl;
	int		new_lvl;
	size_t	len;
	char	*entry;

	*found = true;
	len = ft_strlen(val);
}
