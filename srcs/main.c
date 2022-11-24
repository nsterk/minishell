/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/11/24 21:28:55 by nsterk        ########   odam.nl         */
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
		data.table = parser(data.tokens);
		init_lexer(&data.lexer);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
