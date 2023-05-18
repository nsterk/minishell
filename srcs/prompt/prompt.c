
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	prompt(t_lexer *lexer)
{
	g_state = COMMAND;
	init_signals(); // ? testing
	while (lexer->str == NULL || lexer->str[0] == '\0')
	{
		lexer->str = readline("momoshell-1.0 🐈 ");
		if (!lexer->str)
			exit(EXIT_SUCCESS);
		if (*lexer->str)
			add_history(lexer->str);
	}
	return (1);
}
