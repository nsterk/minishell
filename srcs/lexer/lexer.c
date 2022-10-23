/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/23 15:18:36 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "test.h"

static void	get_token(t_lexer *lexer, t_toktype type);

void	lexer(t_lexer *lexer)
{
	tokenizer(lexer);
}

void	tokenizer(t_lexer *lexer)
{
	while (lexer->input[lexer->start])
	{
		if (!lexer->start)
			get_token(lexer, TOK_CMD);
		else
			get_token(lexer, TOK_ARG);
	}
	token_printHtT(lexer->tokens);
}

static void	get_token(t_lexer *lexer, t_toktype type)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (lexer->input[lexer->start] && ft_isspace(lexer->input[lexer->start]))
		lexer->start++;
	while (lexer->input[lexer->start + i] && !ft_isspace(lexer->input[lexer->start + i]))
		i++;
	tmp = ft_substr(lexer->input, lexer->start, i);
	if (!tmp || token_append(&(lexer->tokens), token_new(tmp, type)))
		exit(EXIT_FAILURE); //!malloc protection
	free(tmp);
	lexer->start += i;
}
