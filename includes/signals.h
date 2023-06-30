/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:51:35 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 14:51:37 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "executor.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

void	init_signals(void);
void	sigquit_handler(int signum);
void	sigint_handler(int signum);

#endif
