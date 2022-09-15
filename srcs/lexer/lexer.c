/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 13:31:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/15 15:00:28 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	display_prompt(void)
{
	write(1, "$ ", 3);
}

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

t_token	*lexer(void)
{
	int		ret;
	char	*raw_in;
	char	*input;
	t_token	*token = NULL;

	ret = 1;
	while (ret)
	{
		display_prompt();
		ret = get_next_line(STDIN_FILENO, &raw_in);
		if (ret < 0)
			exit(1);
		input = ft_strtrim(raw_in, " \t\n\v\r\f");
		free(raw_in);
		if (!input)
			exit(1); 
		if (!ft_strcmp(input, "exit"))
			exit(0);
		// free(input);
	}
	token->word = input;
	// exit(0);
	return (token);
}
