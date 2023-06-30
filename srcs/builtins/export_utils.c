/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:45:39 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:45:42 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	error_message(char *arg, t_data *data)
{
	ft_putstr_fd("momoshell: ", 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(arg, 2);
	ft_putchar_fd('\'', 2);
	ft_putendl_fd(": not a valid identifier", 2);
	data->last_pid = 1;
	return ;
}

static void	st_print_w_second_quote(char *line)
{
	while (*line && *line != '=')
		line++;
	line++;
	while (*line)
	{
		ft_putchar_fd(*line, STDOUT_FILENO);
		line++;
	}
	ft_putchar_fd('\"', STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	st_print_w_first_quote(char *line)
{
	while (*line && *line != '=')
	{
		ft_putchar_fd(*line, STDOUT_FILENO);
		line++;
	}
	ft_putchar_fd(*line, STDOUT_FILENO);
	ft_putchar_fd('\"', STDOUT_FILENO);
}

void	ms_single_export(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		st_print_w_first_quote(envp[i]);
		st_print_w_second_quote(envp[i]);
		i++;
	}
	return ;
}
