
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
		// if (tmp->exp_count && token->flags ^ F_DQUOTE)
	}
	// printf(RED"high level debugging\n"RST);
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
	bool	split;

	if ((*token)->flags ^ F_WORD)
		return ((*token)->next);
	split = false;
	// write(1, "1", 1);
	// token_printHtT(lex->tokens);
	if ((*token)->exp_count && (*token)->flags ^ F_DQUOTE)
		split = true;
	if ((*token)->prev && (*token)->prev->flags & F_WORD)
	{
		tmp = ft_strjoin((*token)->prev->word, (*token)->word);
		check_malloc(tmp, "st_clean_token");
		free((*token)->prev->word);
		(*token)->prev->word = tmp;
		(*token)->word[0] = '\0';
	}
	// write(1, "2", 1);
	// token_printHtT(lex->tokens);
	if (!(*token)->word || !(*(*token)->word))
		return (token_remove(&(lex->tokens), *token));
	// write(1, "3", 1);
	// token_printHtT(lex->tokens);
	if (split)
		return (split_words(lex, token));
	return ((*token)->next);
}

static void	st_rm_tokenspace(t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->tokens;
	while (tmp)
	{
		// token_printHtT(lexer->tokens);
		if (tmp->flags & F_SPACE)
			tmp = token_remove(&(lexer->tokens), tmp);
		else
			tmp = tmp->next;
	}
}
