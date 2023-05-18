
#include "parser.h"
#include "test.h"

static void	print_redir(t_red *red, char *str);
static void	print_args(t_cmd *cmd);

void	print_tbl(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	i = 1;
	tmp = cmd;
	while (tmp)
	{
		printf(WHT_B"command %i: "RST, i);
		print_args(tmp);
		if (tmp->in)
			print_redir(tmp->in, "in");
		if (tmp->out)
			print_redir(tmp->out, "out");
		if (tmp->next && tmp->next->args)
			printf("next: %s\n", tmp->next->args[0]);
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
	while (i <= cmd->argc)
	{
		if (!i)
			printf("[%i] "WHT_B"%s "RST, i, cmd->args[i]);
		else
			printf("[%i] %s ", i, cmd->args[i]);
		if (i == cmd->argc)
			printf("\n");
		i++;
	}
}

static void	print_redir(t_red *red, char *str)
{
	static const char	type[6][15] = {
	[RED_IPUT] = "<",
	[HERE_DOC] = "<<",
	[RED_OPUT] = ">",
	[RED_OPUT_A] = ">>"
	};

	printf(WHT_U"%s"RST": ", str);
	while (red)
	{
		printf(" %s%s-> ", type[red->type], red->filename);
		red = red->next;
	}
	printf("null\n");
	// printf("%s.type: %s\n", str, type[red->type]);
	// printf("%s->filename: %s\n", str, red->filename);
	// printf("%s->fd: %d\n", str, red->fd);
}
