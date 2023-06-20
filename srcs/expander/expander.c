
#include "minishell.h"
#include "test.h"

static bool		st_handle_token(t_token *token, char **envp);
static t_token	*st_clean_token(t_lexer *lexer, t_token **token);
static void		st_rm_tokenspace(t_lexer *lexer);

bool	expander(char **envp, t_lexer *lex)
{
	t_token	*tmp;

	tmp = lex->tokens;
	while (tmp)
	{
		if (st_handle_token(tmp, envp))
			return (true);
		tmp = st_clean_token(lex, &tmp);
	}
	if (lex->tokens) //misschien hier in general doen lex->tokens = rm_tokenspace
		st_rm_tokenspace(lex);
	return (false);
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

static t_token	*st_clean_token(t_lexer *lex, t_token **token)
{
	char	*tmp;

	if ((*token)->flags ^ F_WORD)
		return ((*token)->next);
	if ((*token)->prev && (*token)->prev->flags & F_WORD)
	{
		tmp = ft_strjoin((*token)->prev->word, (*token)->word);
		check_malloc(tmp, "st_clean_token");
		free((*token)->prev->word);
		(*token)->prev->word = tmp;
		(*token)->word[0] = '\0';
	}
	if (!(*token)->word || !(*(*token)->word))
		return (token_remove(&(lex->tokens), *token));
	return ((*token)->next);
}

static void	st_rm_tokenspace(t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->tokens;
	while (tmp)
	{
		if (tmp->flags & F_SPACE)
			tmp = token_remove(&(lexer->tokens), tmp);
		else
			tmp = tmp->next;
	}
}
