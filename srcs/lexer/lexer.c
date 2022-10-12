/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/12 15:25:43 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "test.h"

void	lexer(t_lexer *lexer)
{
	tokenizer(lexer);
}

void	tokenizer(t_lexer *lexer)
{
	size_t	start;
	size_t	i;
	char	*tmp;

	start = 0;
	lexer->tokens = NULL;
	while (lexer->input[start])
	{
		i = 0;
		while (lexer->input[start] && ft_isspace(lexer->input[start]))
			start++;
		while (lexer->input[start + i] && !ft_isspace(lexer->input[start + i]))
			i++;
		tmp = ft_substr(lexer->input, start, i);
		if (!tmp || token_append(&(lexer->tokens), token_new(tmp)))
			exit(EXIT_FAILURE); //!malloc protection
		free(tmp);
		start += i;
	}
	token_printHtT(lexer->tokens);
}
