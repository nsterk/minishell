
#ifndef SIGNALS_H
# define SIGNALS_H

# include "executor.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

void	init_signals(void);
void	sigquit_handler(int signum);
void 	quit_handler(int signum);
void	sigint_handler(int signum);

#endif
