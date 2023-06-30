/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_signals.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 11:55:11 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 11:57:35 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

/**
 * Initiliases signals.
 * 	- SIGINIT + handler => ctrl-C
 * 	- SIGQUIT + SIG_IGN => ctrl-D
 */
void	init_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
