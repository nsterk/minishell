/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:55:15 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/03 10:41:24 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

/**
 * Signal interrupt handler. (signum = 2)
 * 	Handles 'ctrl-C'.
 * 1. Clears the current input line, 
 * 2. prints a newline character, and, 
 * 	if the state is COMMAND, 
 * 		3. resets the input prompt and 
 * 		4. redisplays it correctly.
 */
void	sigint_handler(int signum)
{
	(void)signum;
	rl_replace_line("", 0);
	ft_putchar_fd('\n', 2);
	if (g_state == COMMAND)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

/**
 * Signal quit handler.
 * 	Handles 'ctrl-D'.
 */
void	sigquit_handler(int signum)
{
	ft_putstr_fd("Quit: ", 2);
	ft_putnbr_fd(signum, 2);
	ft_putchar_fd('\n', 2);
}
