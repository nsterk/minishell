/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 10:05:27 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/09 15:19:20 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

// #include <signal.h>
// #include <stdio.h>
// #include <readline/history.h>
// #include <readline/readline.h>

/**
 * 
*/

static void	st_sigint_handler(int signum)
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

void	sigquit_handler(int signum)
{
	ft_putstr_fd("Quit: ", 2);
	ft_putnbr_fd(signum, 2);
	ft_putchar_fd('\n', 2);
}

void	init_signals(void)
{
	// ft_putstr_fd("init signals\n", 2); // ? testing
	signal(SIGINT, st_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
