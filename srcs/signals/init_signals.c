
#include <signals.h>

/**
 * Initiliases signals.
 * 	- SIGINIT + handler => ctrl-C
 * 	- SIGQUIT + SIG_IGN => ctrl-D
 */
void init_signals(void)
{
	// ft_putstr_fd("init signals\n", 2); // ? testing
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
