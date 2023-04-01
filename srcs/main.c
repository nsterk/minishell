/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/04/01 01:12:42 by nsterk        ########   odam.nl         */
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
		if (!lexer(&data.lexer))
		{
			token_printHtT(data.lexer.tokens);
			if (!parser(data.lexer.tokens, &data.cmd))
				printf("do executing \n");
		}
		reinit_data(&data);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
