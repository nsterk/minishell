/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 10:06:43 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/09 11:21:03 by abeznik       ########   odam.nl         */
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

#endif
