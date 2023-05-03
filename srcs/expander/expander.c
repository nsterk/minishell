

#include "minishell.h"

/**
 * Expand environment variable.
 * 	Loop through envp until env var found. Then:
 * 		1. ft_split on str with space as delim --> what if separated by a tab or whatever?
 * 		2. for each str in the array of strings, create a new token of type tok_wrd
 * 		3. insert those tokens into the token list in the place of the original token
 */


/**
 * Kan ook in de lexer zelf al het expanden doen. Dan doe ik ft split op de env var en voor elke str
 * in de array die ft_split terug geeft doe ik delimit token met als type tok_wrd
 * 
 */

int	expander(char **envp, t_lexer *lex)
{
	prep_expansion(lex);
	return (0);
}
