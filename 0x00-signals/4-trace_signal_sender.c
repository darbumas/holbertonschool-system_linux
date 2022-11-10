#include "signals.h"

/**
 * print_handler - helps capture info of an incoming SIQUIT
 * @signum: incoming signal number
 * @info: pointer to struct containing signal info
 * @unused: third parameter to sa_sigaction
 */
void print_handler(int signum, siginfo_t *info, void *unused)
{
	(void)unused;

	if (signum == SIGQUIT)
		printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - defines a handler for the SIGQUIT
 * signal
 * NOTE: the handler will print 'SIGQUIT sent by <pid>
 * each time a SIGQUIT is caught
 * Return: 0 on success, -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_sigaction = print_handler;

	return (sigaction(SIGQUIT, &act, NULL));
}

