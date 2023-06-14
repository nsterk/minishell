
#include "minishell.h"

static bool	st_handle_token(t_token *token, char **envp);
static void	st_clean_token(t_lexer *lexer, t_token **token);
static char	*sorry_arthur(char *s1, char *s2);

// int	expander(char **envp, t_lexer *lex)
// {
// 	t_token *tmp;
// 	t_token	*ryan;

// 	tmp = lex->tokens;
// 	while (tmp)
// 	{ex
// 		if (st_handle_token(tmp, envp))
// 			return (1);
// 		if (tmp->flags & F_WORD && !(*tmp->word))
// 		{
// 			ryan = tmp;
// 			tmp = tmp->prev;
// 			token_remove(&(lex->tokens), ryan);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

int	expander(char **envp, t_lexer *lex)
{
	t_token *tmp;
	// t_token	*ryan;

	tmp = lex->tokens;
	while (tmp)
	{
		if (st_handle_token(tmp, envp))
			return (1);
		if (tmp->flags & F_WORD)
			st_clean_token(lex, &tmp);
		tmp = tmp->next;
	}
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

	if ((*token)->prev && (*token)->prev->flags & F_WORD)
	{
		(*token)->prev->word = sorry_arthur((*token)->prev->word, (*token)->word);
		check_malloc((*token)->prev->word, "st_clean_token");
		(*token)->word[0] = '\0';
	}
	if (!(*token)->word && !(*(*token)->word))
	{
		ryan = *token;
		*token = (*token)->prev;
		lex->tokens = token_remove(&(lex->tokens), ryan);
	} 
	// return (false);
}

static char	*sorry_arthur(char *s1, char *s2) //! this is just strjoin_free without freeing the second string but i just wanted it to stop segfaulting
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (str)
	{
		ft_memcpy(str, s1, len1);
		ft_memcpy(str + len1, s2, len2);
	}
	if (s1)
		free(s1);
	return (str);
}