/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 16:26:52 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/13 21:19:34 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "test.h"

static void	print_redir(t_red red);
static void	print_args(t_cmd *cmd);

void	print_tbl(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	i = 1;
	tmp = cmd;
	while (tmp)
	{
		printf(WHT_B"command %i\n"RST, i);
		print_args(tmp);
		printf(WHT_U"in\n"RST);
		print_redir(tmp->in);
		printf(WHT_U"out\n"RST);
		print_redir(tmp->out);
		if (tmp->next)
			printf("next: %s\n", tmp->next->cmd);
		else
			printf("next: (null)\n");
		tmp = tmp->next;
		i++;
	}
}

static void	print_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	printf("cmd: %s\n", cmd->cmd);
	while (i <= cmd->argc)
	{
		if (!i)
			printf("args: ");
		printf("[%i] %s ", i, cmd->args[i]);
		if (i == cmd->argc)
			printf("\n");
		i++;
	}
}

static void	print_redir(t_red red)
{
	static const char	type[6][15] = {
	[DEFAULT] = "default",
	[RED_IPUT] = "<",
	[HERE_DOC] = "<<",
	[RED_OPUT] = ">",
	[RED_OPUT_A] = ">>"
	};

	printf("type: %s\n", type[red.type]);
	printf("filename: %s\n", red.filename);
	printf("fd: %d\n", red.fd);
}
