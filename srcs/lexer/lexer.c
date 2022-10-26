/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/26 18:14:00 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "test.h"

static void	get_token(t_lexer *lexer, t_toktype type);

void	lexer(t_lexer *lexer)
{
	t_toktype	state;
	//do smth w/ quotes
	while (lexer->input[lexer->start])
	{
		//or do something with quotes here
		while (lexer->input[lexer->start] && ft_isspace(lexer->input[lexer->start]))
			lexer->start++;
		state = get_type(lexer->input[lexer->start]);
		get_token(lexer, state);
	}
	// tokenizer(lexer);
}

void	tokenizer(t_lexer *lexer)
{
	token_printHtT(lexer->tokens);
}

static void	get_token(t_lexer *lexer, t_toktype type)
{
	size_t	i;
 
	i = 0;
	while (get_type(lexer->input[lexer->start + i]) == type)
		i++;
	if (token_append(&(lexer->tokens), token_new2(lexer->start, lexer->start + i, type)))
		exit(EXIT_FAILURE); //!malloc protection
	lexer->start += i;
}


// void	tokenizer(t_lexer *lexer)
// {
// 	while (lexer->input[lexer->start])
// 	{
// 		if (!lexer->start)
// 			get_token(lexer, TOK_CMD);
// 		else
// 			get_token(lexer, TOK_ARG);
// 	}
// 	token_printHtT(lexer->tokens);
// }

// static void	get_token(t_lexer *lexer, t_toktype type)
// {
// 	char	*tmp;
// 	size_t	i;
 
// 	i = 0;
// 	while (lexer->input[lexer->start] && ft_isspace(lexer->input[lexer->start]))
// 		lexer->start++;
// 	while (lexer->input[lexer->start + i] && !ft_isspace(lexer->input[lexer->start + i]))
// 		i++;
// 	tmp = ft_substr(lexer->input, lexer->start, i);
// 	if (!tmp || token_append(&(lexer->tokens), token_new(tmp, type)))
// 		exit(EXIT_FAILURE); //!malloc protection
// 	free(tmp);
// 	lexer->start += i;
// }
