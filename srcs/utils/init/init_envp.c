/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_envp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:32:41 by nsterk        #+#    #+#                 */
/*   Updated: 2023/07/01 21:12:19 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_copy_envp(t_data *data, size_t len, char **envp);
static char	*st_check_lvl(const char *val, bool *found);
static bool	st_check_numeric(const char *val);
static int	st_get_lvl(const char *val);

void	init_envp(t_data *data, char **envp)
{
	size_t	len;

	len = ft_array_len(envp);
	if (!get_envp_value(envp, "SHLVL"))
		len++;
	data->envp = ft_calloc(len + 1, sizeof(char *));
	check_malloc(data->envp, "init_envp **");
	data->envp[len] = NULL;
	st_copy_envp(data, len - 1, envp);
}

static void	st_copy_envp(t_data *data, size_t len, char **envp)
{
	bool	found;

	found = false;
	while (len + 1)
	{
		if (!len && !found)
			break ;
		if (!found && !ft_strncmp("SHLVL=", envp[len], 6))
			data->envp[len] = st_check_lvl(ft_skipspace(envp[len] + 6), &found);
		else
			data->envp[len] = ft_strdup(envp[len]);
		check_malloc(data->envp[len], "init_envp *");
		len--;
	}
	if (!found)
	{
		data->envp[len] = ft_strdup("SHLVL=1");
		check_malloc(data->envp[len], "init_envp");
	}
}

static char	*st_check_lvl(const char *val, bool *found)
{
	int		new_lvl;
	char	*lvl;
	char	*entry;

	*found = true;
	lvl = NULL;
	new_lvl = st_get_lvl(val);
	if (new_lvl >= 0)
	{
		lvl = ft_itoa(new_lvl);
		check_malloc(lvl, "st_check_lvl");
		entry = ft_strjoin("SHLVL=", lvl);
	}
	else
		entry = ft_strdup("SHLVL=");
	if (lvl)
		free(lvl);
	check_malloc(entry, "st_check_lvl");
	return (entry);
}

static int	st_get_lvl(const char *val)
{
	int	old_lvl;

	old_lvl = 0;
	if (st_check_numeric(val))
		old_lvl = ft_atoi(val);
	if (old_lvl < 0)
		return (0);
	if (old_lvl >= 999)
		return (-1);
	return (old_lvl + 1);
}

static bool	st_check_numeric(const char *val)
{
	bool	has_digit;

	has_digit = false;
	while (val && *val)
	{
		if (ft_isdigit(*val))
			has_digit = true;
		else if (!ft_isspace(*val) && *val != '-')
			return (false);
		val++;
	}
	return (has_digit);
}
