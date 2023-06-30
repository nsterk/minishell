/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:55:15 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:57:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

/**
 * Signal interrupt handler. (signum = 2)
 * 	Handles 'ctrl-C'.
 */
static void	sigint_handler(int signum)
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
