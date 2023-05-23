
#include <signals.h>

// #include <signal.h>
// #include <stdio.h>
// #include <readline/history.h>
// #include <readline/readline.h>

/**
 * Signal handling file.
 * 	void signal(void) -
 */

/**
 * Signal interrupt handler. (signum = 2)
 * 	Handles 'ctrl-C'.
 */
void	sigint_handler(int signum)
{
	ft_putstr_fd("sigint_handler\nsignum: ", 2); // ? testing
	ft_putnbr_fd(signum, 2); // ? testing
	ft_putstr_fd("\n", 2); // ? testing
	// printf("signum: %d\n", signum);
	// printf("here\n");
	// (void)signum;
	rl_replace_line("", 0);
	ft_putchar_fd('\n', 2);
	if (g_state == COMMAND)
	{
		rl_on_new_line();
		rl_redisplay();
		// ft_putnbr_fd(g_state, 2); // ? testing
	}
}

/**
 * Signal quit handler.
 * 	Handles 'ctrl-D'.
 */
void sigquit_handler(int signum)
{
	printf("test");
	int fd = open("test_out", O_CREAT | O_RDWR, 0644);
	ft_putstr_fd("Quit: ", 2);
	ft_putstr_fd("Quit: ", fd);
	ft_putnbr_fd(signum, 2);
	ft_putnbr_fd(signum, fd);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', fd);
	close(fd);
	exit(233);
}

/**
 * ! to look into
 */
void quit_handler(int signum)
{
	int fd = open("test_out", O_CREAT | O_RDWR, 0644);
	ft_putstr_fd("Quit: ", 2);
	ft_putstr_fd("Quit: ", fd);
	ft_putnbr_fd(signum, 2);
	ft_putnbr_fd(signum, fd);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', fd);
	close(fd);
}

// int main()
// {
// 	// Set up the signal handler
	// struct sigaction sa;
	// sa.sa_handler = quit_handler;
	// sigaction(SIGQUIT, &sa, NULL);
// 	// Your program code goes here
// 	return 0;
// }