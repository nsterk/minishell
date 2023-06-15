
#include "minishell.h"

static bool	st_handle_token(t_token *token, char **envp);
static void	st_clean_token(t_lexer *lexer, t_token **token);
static void	st_rm_tokenspace(t_lexer *lexer);

int	expander(char **envp, t_lexer *lex)
{
	t_token *tmp;

	tmp = lex->tokens;
	while (tmp)
	{
		if (st_handle_token(tmp, envp))
			return (1);
		if (tmp->flags & F_WORD)
			st_clean_token(lex, &tmp);
		tmp = tmp->next;
	}
	st_rm_tokenspace(lex);
	return (0);
}

static bool	st_handle_token(t_token *token, char **envp)
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
					return (true);
				break ;
			}
			pos++;
		}
		i++;
	}
	return (false);
}

static void	st_clean_token(t_lexer *lex, t_token **token)
{
	t_token	*ryan;
	char	*tmp;

	if ((*token)->prev && (*token)->prev->flags & F_WORD)
	{
		tmp = ft_strjoin((*token)->prev->word, (*token)->word);
		check_malloc(tmp, "st_clean_token");
		free((*token)->prev->word);
		(*token)->prev->word = tmp;
		(*token)->word[0] = '\0';
	}
	if (!(*token)->word || !(*(*token)->word))
	{
		ryan = *token;
		*token = (*token)->prev;
		token_remove(&(lex->tokens), ryan);
	}
}

static void	st_rm_tokenspace(t_lexer *lexer)
{
	t_token	*tmp;
	t_token	*ryan;

	tmp = lexer->tokens;
	while (tmp)
	{
		if (tmp->flags & F_SPACE)
		{
			ryan = tmp;
			tmp = ryan->prev;
			token_remove(&(lexer->tokens), ryan);
		}
		tmp = tmp->next;
	}
}
