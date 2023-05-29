
#include "builtins.h"

static void	st_print_args(char **args, bool add_newline, int i)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (add_newline == true)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

static int	st_check_option(char **args, char c, bool *add_newline)
{
	int		i;
	int		j;

	i = 1;
	while (!ft_strncmp(args[i], "-n", 2))
	{
		j = 2;
		while (args[i][j] == c)
			j++;
		if (args[i][j] == '\0')
		{
			*add_newline = false;
			i++;
		}
		else
			break ;
	}
	return (i);
}

/**
 * Executes the 'echo' builtin.
 * 	1. Check if has a following argument (ex: echo echo)
 * 		- Yes, output = arg
 * 		- No, output = empty (as arg)
 * 	2. Check if -n option
 * 		- output = output + new line
 * 		- Check null output => return failure
 * 	3. Print following arguments.
 * 	4. Set last pid to 0.
 * 	5. Return success.
*/
int	exec_echo(char **args, t_data *data)
{
	bool	add_newline;
	int		i;

	add_newline = true;
	i = 1;
	if (!args[i])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	if (!ft_strncmp(args[1], "-n", 2))
		i = st_check_option(args, args[1][1], &add_newline);
	st_print_args(args, add_newline, i);
	data->last_pid = 0;
	return (EXIT_SUCCESS);
}
