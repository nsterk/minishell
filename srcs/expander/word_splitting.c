
#include "lexer.h"
// #include "test.h"

static void		st_first_param(char *str, t_token *token);
static t_token	*st_other_params(char *str, t_token **token);
static t_token	*st_add_space(t_token **token);

t_token	*split_words(t_token **token)
{
	char	**words;
	t_token	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	words = ft_split((*token)->word, ' ');
	check_malloc(words, "split_words");
	len = ft_array_len(words);
	tmp = *token;
	while (i < len)
	{
		if (!i)
			st_first_param(words[i], tmp);
		else
			tmp = st_other_params(words[i], &tmp);
		if (i < (len - 1))
			tmp = st_add_space(&tmp);
		i++;
	}
	free(words);
	return (tmp);
}

static void	st_first_param(char *str, t_token *token)
{
	if (token->word)
		free(token->word);
	token->word = ft_strdup(str);
	check_malloc(token->word, "st_first_param");
	free(str);
}

static t_token	*st_other_params(char *str, t_token **token)
{
	t_token	*new;
	char	*duppie;

	duppie = ft_strdup(str);
	check_malloc(duppie, "st_other_params 1");
	new = token_new(TOK_WRD, S_WORD, duppie, 0);
	check_malloc(new, "st_other_params 2");
	new->flags |= F_WORD;
	token_addafter(token, new);
	free(str);
	return ((*token)->next);
}

static t_token	*st_add_space(t_token **token)
{
	t_token	*new;

	new = token_new(TOK_SPACE, S_SPACE, NULL, 0);
	check_malloc(new, "st_add_space");
	new->flags |= F_SPACE;
	token_addafter(token, new);
	return ((*token)->next);
}
