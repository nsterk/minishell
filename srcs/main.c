/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/10/13 15:15:01 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enter_shell(void)
{
	t_data	data;

	init_data(&data);
	while (prompt(&data.lexer))
	{
		lexer(&data.lexer);
		data.table = parser(data.tokens);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
