/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:43:16 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/05 12:03:27 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	copy_line_envp(char **new_env, char **env, int new_env_i, int env_i)
{
	int	len;

	len = ft_strlen(env[env_i]);
	new_env[new_env_i] = (char *)ft_calloc((len + 1), sizeof(char));
	check_malloc(new_env[new_env_i], "copy_line_env");
	ft_strlcpy(new_env[new_env_i], env[env_i], len + 1);
}

static int	st_check_export_error(char *arg, int i)
{
	while (arg[i] && ft_strchr("\'\"\\$,.:/[{]}+=-?&*^%#@!~", arg[i]))
		i++;
	if (ft_isalpha(arg[i]) || ft_isalnum(arg[i]))
		return (EXIT_SUCCESS);
	else if (!arg[i])
		return (EXIT_FAILURE);
	else
	{
		i++;
		return (st_check_export_error(arg, i));
	}
}

static char	*st_change_arg(char *arg, char **env, int *i)
{
	int		row;
	char	*env_name;
	char	*arg_var;
	char	*env_var;
	char	*new_arg_var;

	row = search_envp(arg, env, NULL, '+');
	if (row < 0)
		return (arg);
	env_name = ft_calloc(*i + 2, sizeof(char));
	check_malloc(env_name, "change_arg");
	ft_strlcpy(env_name, arg, *i);
	env_var = get_envp_value(env, env_name);
	env_name[*i] = '=';
	arg_var = ft_strdup(&arg[*i + 2]);
	new_arg_var = ft_strjoin(env_var, arg_var);
	free(arg);
	arg = ft_strjoin(env_name, new_arg_var);
	check_malloc(arg, "st_change_arg");
	free(env_name);
	free(arg_var);
	free(new_arg_var);
	return (arg);
}

int	check_for_error(char *arg, int type, char **env)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[i]) && arg[i] != '_')
		return (EXIT_FAILURE);
	while (arg[i] && !ft_strchr("\'\"\\$,.:/[{]}+=-?&*^%#@!~", arg[i]))
		i++;
	if (arg[i] == '+' && arg[i + 1] == '=')
		arg = st_change_arg(arg, env, &i);
	if (arg[i] == '=' && type == EXPORT)
	{
		if (!arg[i + 1])
			return (EXIT_SUCCESS);
		else
		{
			i++;
			return (st_check_export_error(arg, i));
		}
	}
	else if (arg[i] == '\0')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
