/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/10/05 17:46:06 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enter_shell(void)
{
	t_data	data;

	while (prompt(&data.lexer))
	{
		lexer(&data.lexer);
		// print_tokens(data.lexer.tokens, ft_arraylen(data.lexer.words));
		data.table = parser(data.tokens);
		executor(&data.table);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
