
#include "minishell.h"

static int		st_handle_token(t_token *token, char **envp);

int	expander(char **envp, t_lexer *lex)
{
	t_token *tmp;
	t_token	*ryan;

	tmp = lex->tokens;
	while (tmp)
	{
		if (st_handle_token(tmp, envp))
			return (1);
		if (!tmp->word && tmp->flags & F_WORD)
		{
			ryan = tmp;
			tmp = tmp->next;
			
			// - gotta remove this node
		}
		tmp = tmp->next;
	}
	return (0);
}

static int		st_handle_token(t_token *token, char **envp)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	while (i < token->exp_count)
	{
		while (token->word[pos])
		{
			if (token->word[pos] == CH_EXPAND)
			{
				if (do_expanding(token, &(token->exp[i]), &pos, envp))
					return (1);
				break ;
			}
			pos++;
		}
		i++;
	}
	return (0);
}
