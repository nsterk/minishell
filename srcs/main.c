/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:03:59 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/15 13:27:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enter_shell(void)
{
	t_token	*tokens;
	t_table	*table;

	while (1)
	{
		tokens = lexer();
		table = parser(tokens);
	}
}

int	main(void)
{
	enter_shell();
	return (0);
}
