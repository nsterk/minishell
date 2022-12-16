/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/12/07 14:43:37 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test.h"

void	enter_shell(void)
{
	t_data	data;

	init_data(&data);
	while (prompt(&data.lexer))
	{
		lexer(&data.lexer);
		// token_printHtT(data.lexer.tokens);
		data.table = parser(data.tokens);
		reinit_lexer(&data.lexer);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
