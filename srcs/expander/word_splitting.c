
#include "minishell.h"

/**
 * 1. ft_split op token->word (don't lose the **)
 * 2. delete node. prev becomes current.
 * 3. for each word:
 * 		a. create a new token
 * 		b. add_after
 * 		c. token = token->next
 */

bool	split_words(t_lexer *lex, t_token **token)
{
	char	**words;
	size_t	i;
	size_t	len;

	words = ft_split((*token)->word, ' ');
	check_malloc(words, "split_words");
	len = ft_array_len(words);
	while (i < len)
	{

	}
	return (false);
}
