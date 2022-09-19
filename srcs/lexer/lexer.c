/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/19 21:02:00 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

/**
 * think of making fucking wrappers for all fts that deal with malloc so we
 * can catch malloc failures accordingly and stop checking if success each time.
 * Also, it's ridiculous that I'm mallocing input from raw_input when all
 * the only difference is that whitespaces are trimmed. Might as well iterate
 * input from start to find the first non whitespace char and from end to
 * find the last non white space char and then use 
 * ft_strncmp(raw_input + start, "exit, ft_strlen(raw_input" - start - end).
 * Can avoid using malloc for this
 */

void	print_tokens(t_token *tokens, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		printf("token %zu:	%s\n", i, tokens[i].word);
		i++;
	}
}

void	print_list(t_token **lst)
{
	t_token	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		printf("prev: %p		current: %p		next: %p\n", tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
}

void	lexer(t_lexer *lexer)
{
	lexer->nr_tokens = ft_arraylen(lexer->words);
	lexer->tokens = ft_calloc(lexer->nr_tokens, sizeof(t_token));
	if (!lexer->tokens)
		exit(1);
	// printf("Input string is: %s\n", lexer->input);
	fill_tokens(lexer, ft_arraylen(lexer->words));
	print_tokens(lexer->tokens, ft_arraylen(lexer->words));
	print_list(&(lexer->lst));
}

void	fill_tokens(t_lexer *lexer, size_t len)
{
	size_t	i;

	i = 0;
	lexer->lst = NULL;
	while (i < len)
	{
		token_append(&(lexer->lst), token_new(lexer->words[i]));
		lexer->tokens[i].word = ft_strdup((const char *)lexer->words[i]);
		if (!lexer->tokens[i].word)
			exit(EXIT_FAILURE);
		i++;
	}
}
